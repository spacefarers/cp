#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

ll n, d, k;
ll dist[500005], pos[500005], val[500005];

bool validate(ll x){
    memset(dist, -0x3f, sizeof dist);
    dist[0]=0;
    deque<pair<ll, ll>> q;
    ll t=0;
    for (int i=1;i<=n;++i){
        while (!q.empty()&&pos[i]-q.front().first>d+x) q.pop_front();
        while (i>t&&pos[i]-pos[t]>=d-x) {
            while (!q.empty()&&q.back().second<=dist[t]) q.pop_back();
            if (pos[i]-pos[t]<=d+x) q.emplace_back(pos[t], dist[t]);
            t++;
        }
        if (!q.empty()) dist[i]=val[i]+q.front().second;
    }
    return *max_element(dist, dist+n+1)>=k;
}

int main(){
    cin>>n>>d>>k;
    for (int i=1;i<=n;++i){
        ll a, b;
        cin>>a>>b;
        pos[i]=a;
        val[i]=b;
    }
    ll z=-2;
    if (validate(1e9)) {
        for (ll i=1e9;i>=1;i/=2){
            while (!validate(z+i)) z+=i;
        }
    }
    cout<<z+1<<endl;
}