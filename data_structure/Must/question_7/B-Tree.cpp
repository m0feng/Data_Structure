#include "B-Tree.h"

void B_Tree::CreateTree(int num) {
    Insert(num);
}

void B_Tree::Insert(int num) {
    if (root == nullptr) {
        // 如果根节点为空，创建一个新的根节点并插入数据
        root = new Node;
        root->Is_Leaf = true;
        root->keys.push_back(num);
    } else {
        if (Find(num, root)) {
            // 如果数据已经存在于树中，直接返回
            return;
        }
        if (root->keys.size() == M - 1) {
            // 如果根节点已满，创建一个新的根节点，并将原根节点作为子节点进行分裂
            Node* newRoot = new Node;
            newRoot->Child.push_back(root);
            splitChild(newRoot, 0);
            InsertNonFull(newRoot, num);
            root = newRoot;
        } else {
            InsertNonFull(root, num);
        }
    }
}

void B_Tree::InsertNonFull(Node* node, int num) {
    int i = node->keys.size() - 1;
    if (node->Is_Leaf) {
        // 如果节点是叶子节点，直接插入数据
        while (i >= 0 && num < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        if (i == -1)
            node->keys.insert(node->keys.begin(), num);
        else if (i == node->keys.size() - 1)
            node->keys.push_back(num);
        else
            node->keys[i + 1] = num;
    } else {
        // 如果节点是内部节点，找到正确的子节点并递归插入
        while (i >= 0 && num < node->keys[i]){
            i--;
        }
        i++;
        if (node->Child[i]->keys.size() == M - 1) {
            // 如果子节点已满，先进行分裂
            splitChild(node, i);
            if (num > node->keys[i]) {
                i++;
            }
        }
        InsertNonFull(node->Child[i], num);
    }
}

void B_Tree::splitChild(Node* parent, int index) {
    Node* child = parent->Child[index];
    Node* newNode = new Node;
    newNode->Is_Leaf = child->Is_Leaf;

    parent->keys.insert(parent->keys.begin() + index, child->keys[M - 1]);      //孩子子树弹出中间值 进入父节点

    std::move(child->keys.begin() + M, child->keys.end(), std::back_inserter(newNode->keys));
    child->keys.erase(child->keys.begin() + M - 1, child->keys.end());

    if (!child->Is_Leaf) {      //将子树右半部分插入到新生成的节点
        std::move(child->Child.begin() + M, child->Child.end(), std::back_inserter(newNode->Child));
        child->Child.erase(child->Child.begin() + M, child->Child.end());
    }

    parent->Child.insert(parent->Child.begin() + index + 1, newNode);
}

bool B_Tree::Find(int num, Node* node) {
    int i = 0;
    while (i < node->keys.size() && num > node->keys[i]) {
        i++;
    }
    if (i < node->keys.size() && num == node->keys[i]) {
        // 如果找到了目标数据
        return true;
    } else if (node->Is_Leaf) {
        // 如果是叶子节点且未找到目标数据
        return false;
    } else {
        // 在合适的子节点继续查找
        return Find(num, node->Child[i]);
    }
}

void B_Tree::Delete(int num) {
    if (!root) {
        std::cout << "The tree is empty!" << std::endl;
        return;
    }

    DeleteNode(root, num);

    if (root->keys.empty()) {
        // 如果根节点变为空，则更新根指针
        Node* oldRoot = root;
        if (root->Is_Leaf) {
            root = nullptr;
        } else {
            root = root->Child[0];
        }
        delete oldRoot;
    }
}


void B_Tree::DeleteNode(Node *node, int num) {
    int index = 0;
    while (index < node->keys.size() && num > node->keys[index]) {
        index++;
    }

    if (index < node->keys.size() && num == node->keys[index]) {
        if (node->Is_Leaf) {
            // 如果目标数据在叶子节点中，直接删除
            node->keys.erase(node->keys.begin() + index);
        } else {
            Node* predecessor = node->Child[index];
            Node* successor = node->Child[index + 1];

            if (predecessor->keys.size() >= (M + 1) / 2) {
                // 如果前驱节点有足够的数据，则找到前驱数据并递归删除
                int predKey = getPredecessor(predecessor);
                node->keys[index] = predKey;
                DeleteNode(predecessor, predKey);
            } else if (successor->keys.size() >= (M + 1) / 2) {
                // 如果后继节点有足够的数据，则找到后继数据并递归删除
                int succKey = getSuccessor(successor);
                node->keys[index] = succKey;
                DeleteNode(successor, succKey);
            } else {
                // 如果前驱和后继节点都只有(M + 1) / 2 - 1个数据，则合并两个节点并删除目标数据
                mergeNodes(node, predecessor, successor, index);
                DeleteNode(predecessor, num);
            }
        }
    } else {
        if (node->Is_Leaf) {
            return;
        }

        bool flag = (index == node->keys.size());
        Node* child = node->Child[index];

        if (child->keys.size() < (M + 1) / 2) {
            // 如果子节点只有(M + 1) / 2 - 1个数据，则进行修复操作
            fillChild(node, index);
        }

        if (flag && index > node->keys.size()) {
            child = node->Child[index - 1];
        }

        DeleteNode(child, num);
    }
}

int B_Tree::getPredecessor(Node *node) {
    // 找到前驱数据（最右边的叶子节点的最大值）
    while(!node->Is_Leaf){
        node = node->Child[node->Child.size() - 1];
    }
    return node->keys[node->keys.size() - 1];
}

int B_Tree::getSuccessor(Node *node) {
    // 找到后继数据（最左边的叶子节点的最小值）
    while (!node->Is_Leaf) {
        node = node->Child[0];
    }
    return node->keys[0];
}

void B_Tree::mergeNodes(Node *parent, Node *leftChild, Node *rightChild, int index) {
    // 将父节点中的分隔键移动到左子节点末尾
    leftChild->keys.push_back(parent->keys[index]);

    // 将右子节点的数据合并到左子节点
    leftChild->keys.insert(leftChild->keys.end(), rightChild->keys.begin(), rightChild->keys.end());
    leftChild->Child.insert(leftChild->Child.end(), rightChild->Child.begin(), rightChild->Child.end());

    // 删除父节点中的分隔键和右子节点
    parent->keys.erase(parent->keys.begin() + index);
    parent->Child.erase(parent->Child.begin() + index + 1);

    delete rightChild;
}

void B_Tree::fillChild(Node *node, int index) {
    if (index != 0 && node->Child[index - 1]->keys.size() >= (M + 1) / 2) {
        // 从左兄弟节点借一个数据
        borrowFromPrev(node, index);
    } else if (index != node->keys.size() && node->Child[index + 1]->keys.size() >= (M + 1) / 2) {
        // 从右兄弟节点借一个数据
        borrowFromNext(node, index);
    } else {
        if (index != node->keys.size()) {
            // 如果存在右兄弟节点，则将子节点与右兄弟节点进行合并
            mergeNodes(node, node->Child[index], node->Child[index + 1], index);
        } else {
            //如果存在左兄弟节点，则将子节点与左兄弟节点进行合并
            mergeNodes(node, node->Child[index - 1], node->Child[index], index - 1);
        }
    }
}

void B_Tree::borrowFromPrev(Node *node, int index) {
    Node* child = node->Child[index];
    Node* sibling = node->Child[index - 1];

    // 将父节点中的分隔键移动到子节点的开头
    child->keys.insert(child->keys.begin(), node->keys[index - 1]);
    node->keys[index - 1] = sibling->keys[sibling->keys.size() - 1];

    if (!child->Is_Leaf) {
        // 如果子节点不是叶子节点，则将左兄弟节点的最右子节点移动到子节点的开头
        child->Child.insert(child->Child.begin(), sibling->Child[sibling->Child.size() - 1]);
        sibling->Child.erase(sibling->Child.end() - 1);
    }

    sibling->keys.erase(sibling->keys.end() - 1);
}

void B_Tree::borrowFromNext(Node *node, int index) {
    Node* child = node->Child[index];
    Node* sibling = node->Child[index + 1];

    // 将父节点中的分隔键移动到子节点的末尾
    child->keys.push_back(node->keys[index]);
    node->keys[index] = sibling->keys[0];

    if (!child->Is_Leaf) {
        // 如果子节点不是叶子节点，则将右兄弟节点的最左子节点移动到子节点的末尾
        child->Child.push_back(sibling->Child[0]);
        sibling->Child.erase(sibling->Child.begin());
    }

    sibling->keys.erase(sibling->keys.begin());
}