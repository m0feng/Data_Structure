#include<iostream>
#include <vector>
#include <fstream>
using namespace std;
#define INF INT32_MAX


int n,m;
int **Matrix= nullptr;

struct Node{     //点的状态
    bool visit;
    int value;
    Node(){
        visit= false;
        value=INF;
    }
};
vector<Node> dist;

void Dijkstra(int begin){
    for(int i=1;i<=n;i++){        //初始化dist
        dist[i].value=Matrix[begin][i];
    }
    dist[begin].value=0;
    dist[begin].visit= true;
    int count=1,temp,min;
    while(count!=n){
        temp=1;
        min=INF;
        for(int i=1;i<=n;i++){   //寻找value最小且为遍历的点
            if(!dist[i].visit && dist[i].value<min){
                min=dist[i].value;
                temp=i;
            }
        }

        dist[temp].visit= true;
        count++;
        for(int i=1;i<=n;i++){     //遍历一下寻找最短路径
            if(!dist[i].visit && Matrix[temp][i]!=INF && (dist[temp].value+Matrix[temp][i])<dist[i].value){
                dist[i].value=dist[temp].value+Matrix[temp][i];
            }
        }
    }
}

int main(){
    fstream filein;
    filein.open("../test_data.txt",ios::in);
    filein>>n>>m;
    Matrix = new int*[n+1];
    for(int i=1;i<=n;i++){
        Matrix[i]=new int[n+1];
        for(int j=1;j<=n;j++){
            Matrix[i][j]=INF;
        }
    }
    int c,t;
    for(int j=0;j<m;j++){
        filein>>c>>t;
        Matrix[c][t]=Matrix[t][c]=1;
    }

    int p;
    filein>>p;
    for(int i=0;i<p;i++){
        dist.clear();
        dist.resize(n+1);
        filein>>c;
        Dijkstra(c);
        float temp=0;
        dist.erase(dist.begin());
        for(auto it : dist){
            if(it.value!=INF)
                temp+=it.value;
            else{           //图不连通
                temp=0;
                break;
            }
        }
        float r=n-1;
        if(temp==0)
            ::printf("Cc(%d) = %d\n",c,0);
        else
            ::printf("Cc(%d) = %.2f\n",c,r/temp);
    }

    for (int i = 0; i <= n; ++i) {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    filein.close();
    return 0;
}