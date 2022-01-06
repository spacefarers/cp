// created on 2021/6/21 by spacefarers
// problem: C. Dijkstra?

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define ll long long
#define f first
#define s second

using namespace std;

ll dist[100005],trace[100005];
map<ll,ll> paths[100005];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        for (int j=0;j<2;j++){
            if (paths[a][b]==0) paths[a][b]=w;
            paths[a][b]=min(paths[a][b],w);
            swap(a,b);
        }
    }
    memset(dist,0x7f,sizeof dist);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
    q.push({0,1});
    dist[1]=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (dist[u.s]<u.f) continue;
        for (auto i:paths[u.s]){
            if (dist[i.f]>u.f+i.s){
                dist[i.f]=u.f+i.s;
                trace[i.f]=u.s;
                q.push({dist[i.f],i.f});
            }
        }
    }
    if (dist[n]>(ll)1e15){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> ans;
    ll st=n;
    while (st!=1){
        ans.push_back(st);
        st=trace[st];
    }
    cout<<1;
    while (!ans.empty()){
        cout<<" "<<ans.back();
        ans.pop_back();
    }
}