/*
ID: michael419
LANG: C++
TASK: butter
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

int cows[505];
int dist[805];
vector<pair<int, int>> paths[805];

int main(){
    setIO("butter");
    int N, P, C;
    cin>>N>>P>>C;
    for (int i=0;i<N;i++){
        cin>>cows[i];
    }
    for (int i=0;i<C;i++){
        int a, b, c;
        cin>>a>>b>>c;
        paths[a].emplace_back(b, c);
        paths[b].emplace_back(a, c);
    }
    int ans=0x7fffffff;
    for (int i=1;i<=P;i++){
        memset(dist, 0x3f, sizeof dist);
        dist[i]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});
        while (!q.empty()){
            auto u=q.top();
            q.pop();
            if (dist[u.s]<u.f) continue;
            for (auto &j:paths[u.s]){
                if (dist[j.f]>dist[u.s]+j.s){
                    dist[j.f]=dist[u.s]+j.s;
                    q.push({dist[j.f], j.f});
                }
            }
        }
        int c_ans=0;
        for (int j=0;j<N;j++){
            c_ans+=dist[cows[j]];
        }
        ans=min(ans, c_ans);
    }
    cout<<ans<<endl;
}