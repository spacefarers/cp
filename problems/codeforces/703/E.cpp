#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

vector<vector<pair<int, int>>> paths(100005*51);
long long n, m, dist[100005*51];

void add_edge(int u, int v, int w){
    paths[u*51].emplace_back(v*51+w, 0);
    for (int i=1;i<=50;i++){
        paths[u*51+i].emplace_back(v*51, pow(i+w, 2));
    }
}

int main(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[51]=0;
    q.push({0, 51});
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (u.first>dist[u.second]) continue;
        for (auto &i:paths[u.second]){
            if (dist[i.first]>dist[u.second]+i.second){
                dist[i.first]=dist[u.second]+i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (dist[i*51]>(long long)1e12) cout<<-1<<" ";
        else cout<<dist[i*51]<<" ";
    }
}