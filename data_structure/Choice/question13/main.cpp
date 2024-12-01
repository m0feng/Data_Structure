#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> Map;


int main(){
    fstream filein;
    int n,m;
    for(int r=1;r<=2;r++){      //2个test点
        filein.clear();
        cout<<"test"<<to_string(r)<<endl;
        filein.open("../test"+ to_string(r),ios::in);
        filein>>n>>m;
        Map.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                filein>>Map[i][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j+2<m && abs(Map[i][j])== abs(Map[i][j+1]) && abs(Map[i][j+1])== abs(Map[i][j+2]))       //判断横向三格
                    Map[i][j]=Map[i][j+1]=Map[i][j+2]=-abs(Map[i][j]);
                if(i+2<n && abs(Map[i+1][j])== abs(Map[i][j]) && abs(Map[i+1][j])== abs(Map[i+2][j]))        //判断纵向三格
                    Map[i][j]=Map[i+1][j]=Map[i+2][j]=-abs(Map[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(Map[i][j]<0)
                    cout<<"0 ";
                else
                    cout<<Map[i][j]<<" ";
            cout<<endl;
        }
        filein.close();
        Map.clear();
    }
    return 0;
}