/*
ID: michael419
LANG: C++
TASK: maze1
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define f first
#define s second

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

string board[300];
bool paths[105][45][4]; // up, down, left, right
pair<int, int> dir[4]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[105][45];
int w, h;

bool valid(pair<int, int> x){
    return x.f>0&&x.s>0&&x.f<=h&&x.s<=w;
}

int main(){
    setIO("maze1");
    cin>>w>>h;
    for (int i=0;i<=2*h+1;i++){
        getline(cin, board[i]);
    }
    memset(dist, -1, sizeof dist);
    queue<pair<int, int>> q;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            if (board[2*i-1][2*j-1]!='-') paths[i][j][0]=true;
            if (board[2*i+1][2*j-1]!='-') paths[i][j][1]=true;
            if (board[2*i][2*j-2]!='|') paths[i][j][2]=true;
            if (board[2*i][2*j]!='|') paths[i][j][3]=true;
            if ((i==1&&paths[i][j][0])||(i==h&&paths[i][j][1])||(j==1&&paths[i][j][2])||(j==w&&paths[i][j][3])){
                q.push({i, j});
                dist[i][j]=1;
            }
        }
    }
    int step=2;
    while (!q.empty()){
        int sz=q.size();
        for (int i=0;i<sz;i++){
            auto u=q.front();
            q.pop();
            for (int j=0;j<4;j++){
                if (paths[u.f][u.s][j]){
                    auto new_pos=u;
                    new_pos.f+=dir[j].f;
                    new_pos.s+=dir[j].s;
                    if (valid(new_pos)&&dist[new_pos.f][new_pos.s]==-1){
                        dist[new_pos.f][new_pos.s]=step;
                        q.push(new_pos);
                    }
                }
            }
        }
        step++;
    }
    int max_dist=0;
    for (int i=1;i<=h;i++){
        for (int j=1;j<=w;j++){
            max_dist=max(max_dist, dist[i][j]);
        }
    }
    cout<<max_dist<<endl;
}