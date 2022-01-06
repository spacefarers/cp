#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define f first
#define s second
#define ll long long

ll dist[1005], ans[1005], father[1005], ans2[1005];
vector<pair<char, pair<ll, ll>>> cows;
vector<pair<ll, pair<ll, ll>>> compute;

void change(ll x, ll j){
    ans2[x]+=j;
    if (father[x]!=x) change(father[x], j);
}

int main(){
    ll n;
    cin>>n;
    memset(dist, 0x7f, sizeof dist);
    memset(ans2, 0, sizeof ans2);
    memset(ans, 0, sizeof ans);
    for (ll i=0;i<n;i++){
        char a;
        ll b, c;
        cin>>a>>b>>c;
        cows.push_back({a, {b, c}});
        father[i]=i;
    }
    for (ll i=0;i<n;i++){
        for (ll j=i+1;j<n;j++){
            auto a=cows[i], b=cows[j];
            ll time=0;
            if (a.f==b.f) {
                if (a.s.f==b.s.f&&a.f=='N')
                    compute.push_back({abs(a.s.s-b.s.s), {i, j}});
                if (a.s.s==b.s.s&&a.f=='E')
                    compute.push_back({abs(a.s.f-b.s.f), {i, j}});
                continue;
            }
            if (a.f=='N'){
                if (a.s.f<b.s.f||a.s.s>b.s.s) continue;
            } else {
                if (a.s.f>b.s.f||a.s.s<b.s.s) continue;
            }
            if (abs(a.s.s-b.s.s)<abs(a.s.f-b.s.f)){
                time=abs(a.s.f-b.s.f);
            } else if (abs(a.s.s-b.s.s)>abs(a.s.f-b.s.f)) {
                time=abs(a.s.s-b.s.s);
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
                father[i.s.f]=i.s.s;
                ans[i.s.s]++;
            } else {
                dist[i.s.s]=min(dist[i.s.s], abs(a.s.s-b.s.s));
                father[i.s.s]=i.s.f;
                ans[i.s.f]++;
            }
        } else {
            if (a.f=='N'){
                dist[i.s.s]=min(dist[i.s.s], abs(a.s.f-b.s.f));
                father[i.s.s]=i.s.f;
                ans[i.s.f]++;
            } else {
                dist[i.s.f]=min(dist[i.s.f], abs(a.s.f-b.s.f));
                father[i.s.f]=i.s.s;
                ans[i.s.s]++;
            }
        }
    }
    for (int i=0;i<n;i++){
        change(i, ans[i]);
    }
    for (ll i=0;i<n;i++){
        cout<<ans2[i]<<endl;
    }
}