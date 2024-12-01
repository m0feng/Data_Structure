#include <bits/stdc++.h>
#include "AVL_TREE.h"
using namespace std;



int main(){
    Avl_Tree avt;
    fstream filein;
    filein.open("../test",ios::in);
    int t;
    while(filein>>t){
        avt.CreateTree(t);
    }
    int choice;
    cout<<"1.查找"<<endl;
    cout<<"2.插入"<<endl;
    cout<<"3.删除"<<endl;
    cout<<"4.退出"<<endl;
    while(true){
        cout<<"input:";
        cin>>choice;
        if(choice==4){
            break;
        }
        if(choice==1){
            int num;
            cout<<"输入你要查找的数字"<<endl;
            cin>>num;
            if(avt.Find(num,avt.GetRoot())){
                cout<<"Find"<<endl;
            }else{
                cout<<"Not Find"<<endl;
            }
        }else if(choice==2){
            int num;
            cout<<"请输入你要插入的数字"<<endl;
            cin>>num;
            avt.CreateTree(num);
        }else if(choice==3){
            int num;
            cout<<"请输入你要删除的数字"<<endl;
            cin>>num;
            avt.DeleteNode(num);
        }else{
            continue;
        }
    }
    sort
    return 0;
}