/*
ID: michael419
LANG: C++
TASK: msquare
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

vector<int> config(8), target(8);

void op_A(){
    swap(config[0], config[4]);
    swap(config[1], config[5]);
    swap(config[2], config[6]);
    swap(config[3], config[7]);
}

void op_B(){
    int temp1=config[0], temp2=config[4];
    config[0]=config[3];
    config[3]=config[2];
    config[2]=config[1];
    config[1]=temp1;
    config[4]=config[7];
    config[7]=config[6];
    config[6]=config[5];
    config[5]=temp2;
}

void op_C(){
    int temp=config[1];
    config[1]=config[5];
    config[5]=config[6];
    config[6]=config[2];
    config[2]=temp;
}

map<vector<int>, string> path;

int main(){
    setIO("msquare");
    config={1, 2, 3, 4, 8, 7, 6, 5};
    for (int i=0;i<4;i++) cin>>target[i];
    for (int i=7;i>=4;i--) cin>>target[i];
    queue<vector<int>> bfs_q;
    bfs_q.push(config);
    path[config]="X";
    while (!bfs_q.empty()){
        int sz=bfs_q.size();
        while (sz--){
            vector<int> u=bfs_q.front();
            bfs_q.pop();
            if (u==target){
                cout<<path[u].size()-1<<endl;
                cout<<path[u].substr(1, path[u].size()-1)<<endl;
            }
            config=u;
            op_A();
            if (path[config].empty()){
                path[config]=path[u]+"A";
                bfs_q.push(config);
            }
            config=u;
            op_B();
            if (path[config].empty()){
                path[config]=path[u]+"B";
                bfs_q.push(config);
            }
            config=u;
            op_C();
            if (path[config].empty()){
                path[config]=path[u]+"C";
                bfs_q.push(config);
            }
        }
    }
}