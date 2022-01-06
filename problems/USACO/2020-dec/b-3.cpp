#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define f first
#define s second
#define ll long long

ll dist[100];
vector<pair<char, pair<ll, ll>>> cows;
vector<pair<ll, pair<ll, ll>>> compute;

int main(){
    ll n;
    cin>>n;
    memset(dist, 0x7f, sizeof dist);
    for (ll i=0;i<n;i++){
        char a;
        ll b, c;
        cin>>a>>b>>c;
        cows.push_back({a, {b, c}});
    }
    for (ll i=0;i<n;i++){
        for (ll j=i+1;j<n;j++){
            auto a=cows[i], b=cows[j];
            if (a.f==b.f) continue;
            if (a.f=='N'){
                if (a.s.f<b.s.f||a.s.s>b.s.s) continue;
            } else {
                if (a.s.f>b.s.f||a.s.s<b.s.s) continue;
            }
            ll time=0;
            if (abs(a.s.s-b.s.s)<abs(a.s.f-b.s.f)){
                time=abs(a.s.s-b.s.s);
            } else if (abs(a.s.s-b.s.s)>abs(a.s.f-b.s.f)) {
                time=abs(a.s.f-b.s.f);
            }
            if (time==0) continue;
            compute.push_back({time, {i, j}});
        }
    }
    sort(compute.begin(), compute.end());
    for (auto &i:compute){
        if (dist[i.s.f]<i.f||dist[i.s.s]<i.f) continue;
        auto a=cows[i.s.f], b=cows[i.s.s];
        if (abs(a.s.s-b.s.s)>abs(a.s.f-b.s.f)){
            if (a.f=='N'){
                dist[i.s.f]=min(dist[i.s.f], abs(a.s.s-b.s.s));
            } else {
                dist[i.s.s]=min(dist[i.s.s], abs(a.s.s-b.s.s));
            }
        } else {
            if (a.f=='N'){
                dist[i.s.s]=min(dist[i.s.s], abs(a.s.f-b.s.f));
            } else {
                dist[i.s.f]=min(dist[i.s.f], abs(a.s.f-b.s.f));
            }
        }
    }
    for (ll i=0;i<n;i++){
        if (dist[i]>(ll)1e9) cout<<"Infinity"<<endl;
        else cout<<dist[i]<<endl;
    }
}