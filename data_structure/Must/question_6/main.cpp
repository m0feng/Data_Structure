#include "BusGraph.h"
map<string,int> BusId;
map<int,string> BusIdRev;
map<string,int> RoadId;
map<int,string> RoadIdRev;

int main(){
    system("pip install pandas && py ../Excel.py");   //处理excel文件,得到map
    cout<<"Python文件运行完毕"<<endl;
    fstream filein;
    filein.open("../BusMap.txt",ios::in);
    if(!filein.is_open()){
        cout<<"Error"<<endl;
        return 0;
    }
    string tp;
    int cp;
    while (filein>>tp>>cp){
        BusId[tp]=cp;
        BusIdRev[cp]=tp;
    }
    filein.close();
    filein.clear();
    filein.open("../RoadMap.txt",ios::in);
    if(!filein.is_open()){
        cout<<"Error"<<endl;
        return 0;
    }
    while (filein>>tp>>cp){
        RoadId[tp]=cp;
        RoadIdRev[cp]=tp;
    }
    filein.close();
    filein.clear();

    Graph bust;
    bust.CreateGraph();
    string start,end;
    cout<<"Input your start and end"<<endl;
    cin>>start>>end;
    int flag=0;
    for(auto it:BusId){
        if(start==it.first){
            flag=1;
        }
    }
    if(flag==0){
        cout<<"起点输入有误"<<endl;
        return 0;
    }
    flag=0;
    for(auto it:BusId){
        if(start==it.first){
            flag=1;
        }
    }
    if(flag==0){
        cout<<"终点输入有误"<<endl;
        return 0;
    }
    int st=BusId[start],ed=BusId[end];
    bust.SetNum(st,ed);
    vector<string> ans1 = bust.FindMinTransferRoute();
    ans1[ed]=ans1[ed].substr(0,ans1[ed].length()-2);
    cout<<"转车次数最少的乘车路线"<<endl;
    cout<<ans1[ed];
    cout<<endl;
    vector<string> ans2 = bust.FindMinThroughRoute();
    ans2[ed]=ans2[ed].substr(0,ans2[ed].length()-2);
    cout<<"经过站点最少的乘车路线"<<endl;
    cout<<ans2[ed];
    cout<<endl;
    return 0;
}