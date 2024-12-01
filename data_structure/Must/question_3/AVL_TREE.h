#ifndef QUESTION_3_AVL_TREE_H
#define QUESTION_3_AVL_TREE_H

class Avl_Tree{
    private:
        struct Node{
          Node *left,*right;
          int leftHigh,rightHigh;
          int data;
          Node(){
              left=right= nullptr;
              data=leftHigh=rightHigh=0;
          }
        };
        Node *root;

    public:
        Avl_Tree();
        ~Avl_Tree();
        Node *GetRoot();  //获取根节点
        void CreateTree(int num);    //创建AVL树
        Node *Insert(Node *head,int num); //插入操作
        int GetHigh(Node *node);   //获取树的高度
        Node *BalanceLL(Node *head);//对于左子树左节点高的问题进行处理
        Node *BalanceLR(Node *head);//对于左子树右节点高的问题进行处理
        Node *BalanceRR(Node *head);//对于右子树右节点高的问题进行处理
        Node *BalanceRL(Node *head);//对于右子树左节点高的问题进行处理
        bool Find(int num,Node *head); //查找当前数字
        Node *Delete(int num,Node *head);  //删除节点
        int DeleteNode(int num);
};

#endif //QUESTION_3_AVL_TREE_H
