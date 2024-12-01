#include <bits/stdc++.h>
#define ll long long
using namespace std;

int FindMax(vector<ll> value ,vector<ll> cons,int n,int m){        //寻找最大回报
    sort(value.begin(),value.end());
    sort(cons.begin(),cons.end());
    ll sum=0;
    for(int i=0;i<min(n,m);i++){        //从小往大遍历
        if(value[i]<0 && cons[i]<0)    sum+=value[i]*cons[i];
    }
    reverse(value.begin(), value.end());
    reverse(cons.begin(),cons.end());
    for(int i=0;i<min(n,m);i++){         //从大往小遍历
        if(value[i]>0 && cons[i]>0)    sum+=value[i]*cons[i];
    }
    return sum;
}


int main(){
    fstream filein;
    string st="task";
    int n,m;
    vector<ll> value;
    vector<ll> cons;
    for(int i=1;i<=3;i++){          //3个task点
        filein.close();
        filein.clear();
        filein.open("../task"+ to_string(i),ios::in);
        filein>>n;
        cons.clear();
        cons.resize(n);
        for(int j=0;j<n;j++){
            filein>>cons[j];
        }
        filein>>m;
        value.clear();
        value.resize(n);
        for(int j=0;j<n;j++){
            filein>>value[j];
        }
        cout<<FindMax(value,cons,n,m)<<endl;
    }
    filein.close();
    return 0;
}