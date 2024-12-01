#include<bits/stdc++.h>
using namespace std;

vector<int> f;
vector<int> r;
int n,m;

struct Edge{
    int u,v,w;
};
vector<Edge> e;

void Initial()   //初始化
{
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int find(int x)    //查找root
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

bool Union(int x, int y)   //结合
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
            if(Union(x,y)){
                if(find(1)== find(n)){    //找到最大边 直接退出
                    cout<<e[i].w;
                    break;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    f.resize(n+1);
    r.resize(n+1,1);
    e.resize(m);
    for(int i=0;i<m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    sort(e.begin(),e.end(),cmp);     //按边的权值进行排序,方便Krustal算法
    Krustal();
}
