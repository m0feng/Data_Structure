#include <bits/stdc++.h>
using namespace std;

struct Sum{   //存储输入的数字相关信息
    int num;
    int cnt;
    Sum(){
        num=0;
        cnt=0;
    }
};

vector<Sum> tp;
int cp[1001]={0}; //记录次数

bool cmp(Sum p , Sum q){
    if(p.cnt==q.cnt){
        return p.num<q.num;
    }
    return p.cnt>q.cnt;
}


int main(){
    fstream filein;
    filein.open("../test_input.txt",ios::in);
    if(!filein.is_open()){
        exit(0);
    }
    int n;
    filein>>n;
    int k;
    Sum p;
    for(int i=0;i<n;i++){
        filein>>k;
        if(cp[k]==0){
            p.num=k;
            tp.push_back(p);
        }
        cp[k]++;
    }
    for(auto &it : tp){
        it.cnt=cp[it.num];   //赋值该数字出现的次数
    }
    sort(tp.begin(),tp.end(),cmp);  //按题目要求排序
    for(auto &it : tp){
        cout<<it.num<<" "<<it.cnt<<endl;
    }
    filein.close();
    return 0;
}