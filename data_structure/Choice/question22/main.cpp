#include <iostream>
#include <fstream>
#include<vector>
#include <algorithm>
#define INF INT32_MAX
using namespace std;

const int n=10;

float Matrix[n][n];
float dist[n];
bool visit[n];
bool flag= false;
float sum=0;
string path[n];

void Print(){
    for(int i=0;i<n;i++){
        cout<<"v"<<i+1<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(dist[i]!=INF)
            cout<<dist[i]<<"\t";
        else
            cout<<"INF"<<"\t";
    }
    cout<<endl;
    cout<<endl;
}

void Prim(){
    dist[0]=0;
    visit[0]= true;
    path[0]="v1";
    for(int i=1;i<n;i++){
        dist[i]= min(dist[i],Matrix[0][i]);
        path[i]= "v"+to_string(1)+"->"+"v"+ to_string(i+1);
    }
    cout<<"v"<<1<<"加入顶点集合"<<endl;
    cout<<path[0]<<endl;
    Print();
    for(int i=1;i<n;i++){
        int temp=-1;
        int min=INF;
        for(int j=1;j<n;j++){
            if(!visit[j]&&dist[j]<min){
                min=dist[j];
                temp=j;
            }
        }
        if(temp==-1){
            flag= true;
            return;
        }

        visit[temp]= true;
        sum+=dist[temp];
        for(int j=1;j<n;j++){
            if (dist[j]>Matrix[temp][j]){
                dist[j]=Matrix[temp][j];
                path[j]=path[temp]+"->"+"v"+ to_string(j+1);
            }
        }
        cout<<"v"<<temp+1<<"加入顶点集合"<<endl;
        cout<<path[temp]<<endl;
        Print();
    }
}


vector<int> f;
vector<int> r;
int m=14;

struct Edge{
    int u,v;
    float w;
};
vector<Edge> e;

void Initial()
{
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

bool Union(int x, int y)
{
    if (x == y) return false;
    if(r[x]>r[y]){
        f[y]=x;
    }else{
        if(r[x]==r[y]) r[y]++;
        f[x]=y;
    }
    return true;
}

bool cmp(const Edge& a, const Edge& b){
    return a.w<b.w;
}

void Krustal(){
    Initial();
    for(int i=0;i<m;i++){
        int x= find(e[i].u);
        int y= find(e[i].v);
        if(x!=y){
            cout<<e[i].u<<"->"<<e[i].v<<endl;
            if(Union(x,y)){
                sum+=e[i].w;
            }
        }
    }
}

int main(){
    for(int i=0;i<n;i++){
        dist[i]=INF;
        visit[i]= false;
        for(int j=0;j<n;j++){
            Matrix[i][j]=INF;
        }
    }
    int u,v;
    float w;
    fstream filein;
    filein.open("../test1",ios::in);
    for(int i=0;i<14;i++){
        filein>>u>>v>>w;
        Matrix[u-1][v-1]=Matrix[v-1][u-1]=w;
    }
    Prim();
    if(flag){
        cout<<"None"<<endl;
        return 0;
    }
    cout<<"ALL:"<<sum<<endl;
    cout<<endl;
    filein.close();
    filein.clear();
    filein.open("../test1",ios::in);
    sum=0;
    f.resize(n+1);
    r.resize(n+1,1);
    e.resize(m);
    for(int i=0;i<m;i++){
        filein>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e.begin(),e.end(),cmp);
    Krustal();
    cout<<"ALL:"<<sum<<endl;
}