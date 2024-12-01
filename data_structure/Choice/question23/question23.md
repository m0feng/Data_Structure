### 1.题目名称

**平衡二叉树操作的演示**

### 2.代码行数

230行

### 3.算法思想

#### 1.创建AVL树

如果头节点为空，则直接对头节点开地址并赋值，如果非空则判断插入值与根节点值大小，随后进入对应子树。

重复进行上述操作，深入AVL树，直到当前头节点为非空节点停止，对其开地址并赋值。

最后不断回到上一层节点，刷新树的高度并判断AVL树是否平衡，根据平衡情况进行调整。

#### 2.查找

利用递归的思想，将查找值与头节点值进行判断，不断深入子树。

#### 3.删除

采用了递归的方式来搜索要删除的节点，并在删除后重新平衡树。

### 4.主要/核心函数分析

#### Insert

```c++
Avl_Tree::Node *Avl_Tree::Insert(Node *head,int num) {
    if(head == nullptr){
        head=new Node;
        head->data=num;
    }else if(num<head->data){
        head->left=Insert(head->left,num);  //进入左子树
        if(GetHigh(head->left)- GetHigh(head->right)==2){   //判断是否平衡
            if(num<head->left->data){
                head=BalanceLL(head);
            }else{
                head=BalanceLR(head);
            }
        }
    }else if(num>head->data){
        head->right=Insert(head->right,num);    //进入右子树
        if(GetHigh(head->right)- GetHigh(head->left)==2){   //判断是否平衡
            if(num<head->right->data){
                head=BalanceRL(head);
            }else{
                head=BalanceRR(head);
            }
        }
    }

    head->leftHigh= GetHigh(head->left);    //刷新树的高度
    head->rightHigh= GetHigh(head->right);
    return head;
}
```

1. 函数接受一个`Node* head`和一个`int num`作为参数。它会递归地将值为`num`的新节点插入到以`head`为根的AVL树中。
2. 如果`head`为空，则创建一个值为`num`的新节点，并将其赋给`head`。
3. 如果`num`小于当前节点的值（`head->data`），则在左子树上递归调用`Insert`函数。插入后，它会检查左子树的高度和右子树的高度之差是否为2。如果是，则根据具体情况进行LL型或LR型旋转。
4. 如果`num`大于当前节点的值（`head->data`），则在右子树上递归调用`Insert`函数。插入后，它会检查右子树的高度和左子树的高度之差是否为2。如果是，则根据具体情况进行RR型或RL型旋转。
5. 最后返回根节点`head`。

这个函数实现了在AVL树中插入新节点并保持树的平衡。

#### Balance

```c++
Avl_Tree::Node *Avl_Tree::BalanceLL(Node *head)：LL型旋转，保持平衡。
Avl_Tree::Node *Avl_Tree::BalanceLR(Node *head)：LR型旋转，保持平衡。
Avl_Tree::Node *Avl_Tree::BalanceRR(Node *head)：RR型旋转，保持平衡。
Avl_Tree::Node *Avl_Tree::BalanceRL(Node *head)：RL型旋转，保持平衡。
```

#### Find

```c++
bool Avl_Tree::Find(int num, Node *head) {
    if(head== nullptr) return false;
    if(head->data==num) return true;
    if(head->data>num)  return Find(num,head->left);
    if(head->data<num)  return Find(num,head->right);
}
```

这个函数是一个递归函数，用于在AVL树中搜索给定的数字。它接受两个参数：要搜索的数字和树的头节点。

函数首先检查头节点是否为空，如果是，则返回false，表示树中未找到该数字。如果头节点的数据等于给定的数字，则返回true，表示在树中找到了该数字。

如果头节点的数据大于给定的数字，则在头节点的左子树上递归调用Find函数。如果头节点的数据小于给定的数字，则在头节点的右子树上递归调用Find函数。

#### Delete

```c++
Avl_Tree::Node* Avl_Tree::Delete(int num, Node *head) {
    if(head== nullptr)
        return nullptr;
    if(num<head->data){         //寻找目标节点
        head->left= Delete(num,head->left);
        if(GetHigh(head->left)- GetHigh(head->right)==2){
            if(num<head->left->data){
                head=BalanceLL(head);
            }else{
                head=BalanceLR(head);
            }
        }
    }else if(num>head->data){
        head->right= Delete(num,head->right);
        if(GetHigh(head->right)- GetHigh(head->left)==2){
            if(num<head->right->data){
                head=BalanceRL(head);
            }else{
                head=BalanceRR(head);
            }
        }
    }else{        //找到该节点
        if(head->left!= nullptr && head->right!= nullptr){        //非叶子节点
            if(GetHigh(head->left) > GetHigh(head->right)){
                Node *p=head->left;
                while(p->right!= nullptr){       //寻找左子树最大值
                    p=p->right;
                }
                head->data=p->data;
                head->left= Delete(p->data,head->left);
            }else{
                Node *p=head->right;
                while(p->left!= nullptr){      //寻找右子树最大值
                    p=p->left;
                }
                head->data=p->data;          //置根节点
                head->right= Delete(p->data,head->right); //删除尾部节点
            }
        }else if(head->left== nullptr && head->right== nullptr){    //叶子节点直接置空
            head= nullptr;
        }else if(head->left!= nullptr && head->right== nullptr){    //把非空子树移上去
            Node *p=head;
            head=head->left;
            delete p;
        }else{
            Node *p=head;
            head=head->right;
            delete p;
        }
    }
    return head;
}
```

这个函数是用于在AVL树中删除指定值的节点。它采用了递归的方式来搜索要删除的节点，并在删除后重新平衡树。

函数首先检查头节点是否为空，如果是，则返回空指针。然后它比较要删除的值和当前节点的值，根据比较结果决定是向左子树还是右子树递归调用Delete函数。在递归调用后，函数会检查树是否失去平衡，并进行相应的旋转操作来恢复平衡。

如果找到了要删除的节点，函数会根据节点的情况进行不同的处理：
- 如果节点是非叶子节点，则找到左子树中的最大值或右子树中的最小值来替换当前节点，并递归删除该最大值或最小值节点。
- 如果节点是叶子节点，则直接将其置为空。
- 如果节点只有一个子树，则将子树移动到当前节点的位置，并删除原节点。

最后，函数返回更新后的头节点。

### 5.测试数据(规模,测试次数)

规模:随机选取的20个数

测试次数:5

测试用例:见测试文件

### 6.运行结果

```txt
F:\data_structure\Choice\question23\cmake-build-debug\question_3.exe
1.查找
2.插入
3.删除
4.退出
input:1
输入你要查找的数字
1
Find
input:2
请输入你要插入的数字
9999
input:1
输入你要查找的数字
9999
Find
input:3
请输入你要删除的数字
9999
input:1
输入你要查找的数字
9999
Not Find
input:4

进程已结束,退出代码0

```

### 7.时间复杂度分析

`Insert` 函数的时间复杂度取决于树的高度，最坏情况下为 O(log n)，其中 n 是树中节点的数量。在最坏情况下，需要沿着树的高度向下进行插入，并在插入后重新平衡树。

`Delete` 函数的时间复杂度也取决于树的高度，在最坏情况下为 O(log n)，因为它需要搜索要删除的节点，并在删除后重新平衡树。

1. 查找操作（`Find` 函数）的时间复杂度也与树的高度相关，在最坏情况下为 O(log n)。
4. 平衡操作（LL、LR、RL、RR）的时间复杂度都是 O(1)，因为它们只是重新连接节点，不需要遍历整个树。

综上所述，在最坏情况下，函数时间复杂度是O(log n)。

### 8.结果截屏图片

![](F:\data_structure\Choice\question23\output.png)

### 9.心得体会

通过实现AVL树，对其的基本性质更加熟悉，同时对该树增删查的代码实现有了深入的了解。