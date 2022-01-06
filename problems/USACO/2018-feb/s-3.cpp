#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

ll n, level=0;

map<ll, ll> mp;

int main() {
    setIO("teleport");
    cin>>n;
    for (int i=1;i<=n;i++){
        ll a, b;
        cin>>a>>b;
        level+=abs(a-b);
        if (abs(a)>=abs(a-b)) continue;
        mp[b]+=2;
        if ((a<0&&a<b)||(a>=b&&a>=0)) {mp[0]--;mp[2*b]--;}
        if ((a>=b&&a<=0)||(a<b&&a>0)) {mp[2*a]--;mp[2*b-2*a]--;}
    }
    ll c_slope=0, last_pos=-2000000000, ans=level;
    trav(i, mp){
        ll pos=i.f;
        ll slope=i.s;
        level+=c_slope*(pos-last_pos);
        last_pos=pos;
        c_slope+=slope;
        ans=min(ans, level);
    }
    cout<<ans<<endl;
    return 0;
}