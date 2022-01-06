// created on 2021/7/4 by spacefarers
// problem: D - Shortest Path Queries 2

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define f first
#define s second

using namespace std;

vector<pair<ll,ll>> paths[405];

ll dist[405],temp[405];
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;

void run(int j){
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (dist[u.s]<u.f) continue;
        for (auto k:paths[u.s]){
            temp[k.f]=min(temp[k.f],u.f+k.s);
            if (k.f>j) continue;
            if (dist[k.f]>u.f+k.s){
                dist[k.f]=u.f+k.s;
                q.push({dist[k.f],k.f});
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        paths[a].emplace_back(b,c);
    }
    ll ans=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) dist[j]=1e14,temp[j]=1e14;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q2;
        swap(q,q2);
        temp[i]=0;
        dist[i]=0;
        q.push({temp[i],i});
        run(-1);
        for (int j=1;j<=n;j++){
            q.push({temp[j],j});
            dist[j]=temp[j];
            run(j);
            for (int k=1;k<=n;k++){
                ll c_ans=temp[k];
                if (c_ans<(ll)1e13) ans+=c_ans;
            }
        }
    }
    cout<<ans<<endl;
}