#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define f first
#define s second
#define pi pair<int, int>
#define vpi vector<pi>
#define pb push_back

map<int, vector<pair<int, pi>>> paths;
int dist[1005];

int main(){
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        paths[a].pb({b, {c, d}});
        paths[b].pb({a, {c, d}});
    }
//    memset(dist, 0, sizeof dist);
    priority_queue<pair<int, pair<int, pi>>, vector<pair<int, pair<int, pi>>>, greater<pair<int, pair<int, pi>>>> q;
    q.push({0, {1, {0, 0x7fffffff}}});
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        for (auto &i:paths[u.s.f]){
            int new_dist=min(u.s.s.s, i.s.s)*1000000/(u.s.s.f+i.s.f);
            if (dist[i.f]<new_dist){
                dist[i.f]=new_dist;
                q.push({dist[i.f], {i.f, {u.s.s.f+i.s.f, min(u.s.s.s, i.s.s)}}});
            }
        }
    }
    cout<<dist[n]<<endl;
}