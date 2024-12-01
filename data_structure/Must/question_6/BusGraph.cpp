#include "BusGraph.h"

Graph::Graph() {
    RoadSum.resize(TestLength()+5);
    for(auto &it : RoadSum){
        it=new BusRoad;
    }
    start=-1,end=-1;
    StationSum.resize(7000);
    for(auto &it:BusId){
        StationSum[it.second]=new StationRoad;
        StationSum[it.second]->id=it.second;
    }

}


Graph::~Graph() {
    for (auto road : RoadSum) {
        delete road;
    }
    RoadSum.clear();

    for (auto st : StationSum) {
        delete st;
    }
    StationSum.clear();
}


void Graph::SetNum(int s, int t) {
    start=s;
    end=t;
}


int Graph::TestLength() {
    fstream fi;
    fi.open("../Nanj_Bus/Nanj_Bus.txt",ios::in);
    if(!fi.is_open()){
        cout<<"Read Error"<<endl;
        exit(0);
    }
    int temp1,temp2,temp3;
    int maxr=-1;
    while(fi>>temp1>>temp2>>temp3){
        maxr=(maxr>temp1)?maxr:temp1;
    }
    fi.close();
    return maxr;
}


void Graph::CreateGraph() {
    fstream fi;
    fi.open("../Nanj_Bus/Nanj_Bus.txt",ios::in);
    if(!fi.is_open()){
        cout<<"Read Error"<<endl;
        exit(0);
    }
    int ld,nd,wd;
    while (fi>>ld>>nd>>wd){
        RoadSum[ld]->BusStation.push_back(wd);
        StationSum[wd]->Road.push_back(ld);
        RoadSum[ld]->nStation[wd]=nd;
    }
    fi.close();
}


vector<string> Graph::FindMinTransferRoute() {
    if (start == -1 || end == -1) {
        cout << "未设置起始站点和目标站点" << endl;
        return {};
    }

    unordered_set<int> visited;
    queue<StationRoad*> q;
    vector<string> Path(7000);
    vector<int> PathCount(7000,0);
    for(auto &it:Path){
        it= BusIdRev[start]+"->";
    }

    StationRoad* startStation = StationSum[start];
    q.push(startStation);
    while (!q.empty()) {    //Bfs算法遍历
        StationRoad* current = q.front();
        q.pop();

        int currentStation = current->id;
        vector<int> currentRoad = current->Road;

        if (currentStation == end) {
            return Path;
        }

        if (visited.count(currentStation) > 0) {
            continue;
        }

        visited.insert(currentStation);

        for (int bus : currentRoad) {       //站->线
            vector<int> stops = RoadSum[bus]->BusStation;
            for (int stop : stops) {        //线->站
                if (visited.count(stop)<=0) {
                    StationRoad* nextStation = StationSum[stop];
                    q.push(nextStation);
                    if(PathCount[stop]==0 || PathCount[stop]>PathCount[currentStation]+1){         //动规 min(stop经过的路线数 ,当前节点经过的路线数+1)
                        Path[stop]=Path[currentStation]+"("+ RoadIdRev[bus]+")"+"->"+ BusIdRev[stop]+"->";
                        PathCount[stop]++;
                    }

                }
            }
        }
    }

    cout << "无法找到起始站点到目标站点的路线" << endl;
    return {};
}



vector<string> Graph::FindMinThroughRoute() {
    if (start == -1 || end == -1) {
        cout << "未设置起始站点和目标站点" << endl;
        return {};
    }

    vector<bool> visited(7000, false);
    vector<string> Path(7000, "");
    vector<int> PathCount(7000, 0);
    for (auto &it : Path) {
        it = BusIdRev[start] + "->";
    }

    stack<int> stationStack;
    stationStack.push(start);

    while (!stationStack.empty()) {          //dfs遍历
        int currentStation = stationStack.top();
        stationStack.pop();

        if (currentStation == end)
            break;

        visited[currentStation] = true;

        StationRoad* current = StationSum[currentStation];
        vector<int> currentRoad = current->Road;

        for (int bus : currentRoad) {
            vector<int> stops = RoadSum[bus]->BusStation;
            for (int stop : stops) {
                if (!visited[stop]) {
                    stationStack.push(stop);
                    int k = PathCount[currentStation] + abs(RoadSum[bus]->nStation[stop] - RoadSum[bus]->nStation[currentStation]);
                    if (PathCount[stop] == 0 || PathCount[stop] > k) {    // 动态规划：min(stop经过的站点数,当前节点经过的站点数+到该节点的站点数)
                        Path[stop] = Path[currentStation] + "(" + RoadIdRev[bus] + ")" + "->" + BusIdRev[stop] + "->";
                        PathCount[stop] = k;
                    }
                }
            }
        }
    }

    return Path;
}





















