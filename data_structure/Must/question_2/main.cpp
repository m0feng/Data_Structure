#include<bits/stdc++.h>
using namespace std;

const int n=30;
int Maze[n][n];    //存储地图
struct Node{
    int x,y;
}input,output;
stack<string> PathT;   //记录经过的路径
Node Direction[4]={{0,-1},{0,1},{-1,0},{1,0}};    //4种方向操作
int flag=0;

void Read_File(const string& filename){
    fstream filein;
    filein.open(filename,ios::in);
    if(!filein.is_open()){
        cout<<"Read Error"<<endl;
        exit(0);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            filein>>Maze[i][j];
        }
    }
    filein.close();
}

void generate(){        //生成起点和终点
    srand((unsigned)time(NULL));
    while(1){
        input.x=rand()%30;
        input.y=rand()%30;
        if(Maze[input.x][input.y]==1)
            break;
    }
    while(1){
        output.x=rand()%30;
        output.y=rand()%30;
        if(Maze[output.x][output.y]==1 &&( input.x!=output.x || input.y!=output.y))
            break;
    }
}

void PrintMap(){     //打印地图
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<Maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

string ToString(Node p){
    return "("+ to_string(p.x)+","+ to_string(p.y)+")";
}


void Bfs(){                         //进行广度优先搜索
    queue<Node> NodeQueue;
    NodeQueue.push(input);
    queue<string> Path;
    Path.push(ToString(input));
    Maze[input.x][input.y]=0;
    Node p;
    string pt,ct;
    while(!NodeQueue.empty()){
        p.x=NodeQueue.front().x;
        p.y=NodeQueue.front().y;
        pt=Path.front();
        NodeQueue.pop();
        Path.pop();
        for(int i=0;i<4;i++){
            p.x+=Direction[i].x;
            p.y+=Direction[i].y;
            if(p.x>=0&&p.x<30&&p.y>=0&&p.y<30&&Maze[p.x][p.y]==1){    //判断是否越界
                NodeQueue.push(p);
                Maze[p.x][p.y]=0;
                ct=pt+"->"+ ToString(p);
                Path.push(ct);
                if(p.x==output.x&&p.y==output.y){
                    cout<<ct<<endl;
                    return;
                }
            }
            p.x-=Direction[i].x;
            p.y-=Direction[i].y;
        }
    }
}

void Dfs(Node in){            //进行深度搜索算法
    Node p;
    if(in.x==input.x&&in.y==input.y){
        flag=1;
        string pt;
        while(!PathT.empty()){
            if(PathT.size()!=1)
                cout<<PathT.top()<<"->";
            else
                cout<<PathT.top();
            PathT.pop();
        }
        return;
    }
    p.x=in.x,p.y=in.y;
    for(int i=0;i<4;i++){     //遍历四个方向
        p.x+=Direction[i].x;
        p.y+=Direction[i].y;
        if(p.x>=0&&p.x<30&&p.y>=0&&p.y<30&&Maze[p.x][p.y]==1){
            Maze[p.x][p.y]=0;
            PathT.push(ToString(p));
            Dfs(p);
            if(flag!=1){
                Maze[p.x][p.y]=1;
                PathT.pop();
            }
        }
        p.x-=Direction[i].x;
        p.y-=Direction[i].y;
    }
}

int main(){
    Read_File("../maze.txt");
    generate();
    PrintMap();   // 1为可以走 0为不可以走
    printf("起点为(%d,%d),终点为(%d,%d)\n",input.x,input.y,output.x,output.y);
    cout<<"Bfs"<<endl;
    Bfs();
    Read_File("../maze.txt");
    PathT.push(ToString(output));
    Maze[output.x][output.y]=0;
    cout<<"Dfs"<<endl;
    Dfs(output);
    return 0;
}