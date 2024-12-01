#ifndef QUESTION_7_B_TREE_H
#define QUESTION_7_B_TREE_H
#include <bits/stdc++.h>
using namespace std;

class B_Tree{
private:
    struct Node{
        bool Is_Leaf;
        vector<Node*> Child;
        vector<int> keys;
        Node(){
            Is_Leaf= false;
        }
    };
    const int M=4;
    Node *root;
public:
    B_Tree(){ root= nullptr; };
    ~B_Tree(){ root= nullptr; };
    Node *GetRoot() { return root; };   //获取根节点
    void CreateTree(int num);           //创建树
    void Insert(int num);               //插入节点
    void InsertNonFull(Node *node , int num);  //如果根节点非空则插入
    void splitChild(Node *parent,int index);    //节点满则分裂
    bool Find(int num,Node *head);              //查找节点
    void Delete(int num);                       //删除节点
    void DeleteNode(Node *node,int num);
    int getPredecessor(Node *node);            //获得前驱值
    int getSuccessor(Node* node);               //获得后继值
    void mergeNodes(Node* parent,Node* leftChild,Node* rightChild,int index);   //父节点的一个键值与其左子节点和右子节点进行合并
    void fillChild(Node* node,int index);   //删除节点后填充其子节点
    void borrowFromPrev(Node* node ,int index); //从前一个兄弟节点借一个键值
    void borrowFromNext(Node* node ,int index); //从后一个兄弟节点借一个键值
};

#endif //QUESTION_7_B_TREE_H
