#include "AVL_TREE.h"
#include <bits/stdc++.h>
Avl_Tree::Avl_Tree() {
    root= nullptr;
}

Avl_Tree::~Avl_Tree() {
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
        head->left=Insert(head->left,num);  //����������
        if(GetHigh(head->left)- GetHigh(head->right)==2){   //�ж��Ƿ�ƽ��
            if(num<head->left->data){
                head=BalanceLL(head);
            }else{
                head=BalanceLR(head);
            }
        }
    }else if(num>head->data){
        head->right=Insert(head->right,num);    //����������
        if(GetHigh(head->right)- GetHigh(head->left)==2){   //�ж��Ƿ�ƽ��
            if(num<head->right->data){
                head=BalanceRL(head);
            }else{
                head=BalanceRR(head);
            }
        }
    }

    head->leftHigh= GetHigh(head->left);    //ˢ�����ĸ߶�
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
    if(num<head->data){         //Ѱ��Ŀ��ڵ�
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
    }else{        //�ҵ��ýڵ�
        if(head->left!= nullptr && head->right!= nullptr){        //��Ҷ�ӽڵ�
            if(GetHigh(head->left) > GetHigh(head->right)){
                Node *p=head->left;
                while(p->right!= nullptr){       //Ѱ�����������ֵ
                    p=p->right;
                }
                head->data=p->data;
                head->left= Delete(p->data,head->left);
            }else{
                Node *p=head->right;
                while(p->left!= nullptr){      //Ѱ����������Сֵ
                    p=p->left;
                }
                head->data=p->data;          //�ø��ڵ�
                head->right= Delete(p->data,head->right); //ɾ��β���ڵ�
            }
        }else if(head->left== nullptr && head->right== nullptr){    //Ҷ�ӽڵ�ֱ���ÿ�
            head= nullptr;
        }else if(head->left!= nullptr && head->right== nullptr){    //�ѷǿ���������ȥ
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