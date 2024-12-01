#ifndef EXCEL_PY_BUSGRAPH_H
#define EXCEL_PY_BUSGRAPH_H
#include <bits/stdc++.h>
using namespace std;

extern map<string,int> BusId;
extern map<int,string> BusIdRev;
extern map<string,int> RoadId;
extern map<int,string> RoadIdRev;

class Graph{
    private:
        int start;
        int end;

        struct BusRoad{     //路线
            vector<int> BusStation;  //站点
            int nStation[7000]={0};  //线内id
            BusRoad(){
                BusStation.clear();
            }
        };

        struct StationRoad{     //站
            vector<int> Road;  //路
            int id;             //站点id
            StationRoad(){
                id=-1;
                Road.clear();
            }
        };
        vector<StationRoad*> StationSum;
        vector<BusRoad*> RoadSum;
    public:
        Graph();
        ~Graph();
        void SetNum(int s , int t);  //设置起点和终点
        int TestLength();           //测试站点长度
        void CreateGraph();         //创建公交站点图
        vector<string> FindMinTransferRoute();  //最小转站
        vector<string> FindMinThroughRoute();   //最小经过站
};


#endif //EXCEL_PY_BUSGRAPH_H
