#include <bits/stdc++.h>
#include "AVL_TREE.h"
using namespace std;

const int kSize=10000;
int prime[kSize];
int prime_size = 0;
bool visited[kSize]={0};

void Select_Prime(){      //素数筛
    memset(visited, 0, sizeof(bool));
    for (int i = 2; i < kSize; ++i) {
        if (!visited[i]) {
            prime[prime_size++] = i;
            for (int j = i * i; j < kSize; j += i) {
                visited[j] = true;
            }
        }
    }

}

int main(){
    Select_Prime();
    Avl_Tree avt;
    for(int i=0;i<prime_size;i++){
        avt.CreateTree(prime[i]);
    }
    cout<<"AVL树构建完成"<<endl;
    fstream Write_tree1;
    Write_tree1.open("../tree1.txt", ios::out);
    if(!Write_tree1.is_open()){
        cout<<"Write_tree1 open error"<<endl;
        exit(0);
    }
    for(int i=200;i<=300;i++){             //task1
        string pt= to_string(i);
        if(avt.Find(i,avt.GetRoot()))
            Write_tree1<<pt+" yes"<<endl;
        else
            Write_tree1<<pt+" no"<<endl;
    }
    cout<<"tree1.txt 写入完成"<<endl;
    Write_tree1.close();

    for(int i=500;i<=2000;i++){          //task2
        if(!visited[i]){
            avt.DeleteNode(i);
        }
    }

    fstream Write_tree2;
    Write_tree2.open("../tree2.txt", ios::out);
    if(!Write_tree2.is_open()){
        cout<<"Write_tree2 open error"<<endl;
        exit(0);
    }
    for(int i=600;i<=700;i++){
        if(!visited[i]){
            string pt= to_string(i);
            if(avt.Find(i,avt.GetRoot()))
                Write_tree2<<pt+" yes"<<endl;
            else
                Write_tree2<<pt+" no"<<endl;
        }
    }
    cout<<"tree2.txt 写入完成"<<endl;
    Write_tree2.close();

    for(int i=0;i<=1000;i+=2){         //task3
        avt.CreateTree(i);
    }

    fstream Write_tree3;
    Write_tree3.open("../tree3.txt", ios::out);
    if(!Write_tree3.is_open()){
        cout<<"Write_tree3 open error"<<endl;
        exit(0);
    }
    for(int i=100;i<=200;i+=2){
        string pt= to_string(i);
        if(avt.Find(i,avt.GetRoot()))
            Write_tree3<<pt+" yes"<<endl;
        else
            Write_tree3<<pt+" no"<<endl;
    }
    cout<<"tree3.txt 写入完成"<<endl;
    Write_tree3.close();

    return 0;
}