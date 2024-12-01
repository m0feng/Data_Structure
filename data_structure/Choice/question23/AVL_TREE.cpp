#include "AVL_TREE.h"
#include <bits/stdc++.h>
Avl_Tree::Avl_Tree() {
    root= nullptr;
}

Avl_Tree::Node *Avl_Tree::GetRoot() {
    return root;
}

void Avl_Tree::CreateTree(int num) {
    root = Insert(root,num);
}

int Avl_Tree::GetHigh(Node *node) {
    if(node== nullptr) return 0;
    return std::max(GetHigh(node->left), GetHigh(node->right))+1;
}

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


Avl_Tree::Node *Avl_Tree::BalanceLL(Node *head) {
    Node *temp=head->left;
    head->left=temp->right;
    temp->right=head;
    temp->leftHigh= GetHigh(temp->left);
    temp->rightHigh= GetHigh(temp->right);
    return temp;
}


Avl_Tree::Node *Avl_Tree::BalanceLR(Node *head) {
    head->left= BalanceRR(head->left);
    return BalanceLL(head);
}


Avl_Tree::Node *Avl_Tree::BalanceRR(Node *head) {
    Node *temp=head->right;
    head->right=temp->left;
    temp->left=head;
    temp->leftHigh= GetHigh(temp->left);
    temp->rightHigh= GetHigh(temp->right);
    return temp;
}


Avl_Tree::Node *Avl_Tree::BalanceRL(Node *head) {
    head->right= BalanceLL(head->right);
    return BalanceRR(head);
}

bool Avl_Tree::Find(int num, Node *head) {
    if(head== nullptr) return false;
    if(head->data==num) return true;
    if(head->data>num)  return Find(num,head->left);
    if(head->data<num)  return Find(num,head->right);
}

int Avl_Tree::DeleteNode(int num) {
    if(!Find(num,root)){
        std::cout<<"Not Find"<<std::endl;
        return -1;
    }
    root=Delete(num,root);
}

Avl_Tree::Node* Avl_Tree::Delete(int num, Node *head) {
    if(head== nullptr)
        return nullptr;
    if(num<head->data){
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