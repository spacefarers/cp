#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

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

multiset<ll> chicks;
vector<pair<ll, ll>> cows;

int main() {
    setIO("helpcross");
    ll c, n;
    cin>>c>>n;
    for (ll i=0;i<c;i++){
        ll a;
        cin>>a;
        chicks.insert(a);
    }
    for (ll i=0;i<n;i++){
        ll a, b;
        cin>>a>>b;
        cows.emplace_back(b, a);
    }
    sort(all(cows));
    ll ans=0;
    trav (i, cows){
        auto lb=chicks.lower_bound(i.s);
        if (lb!=chicks.end()&&*lb<=i.f) {
            ans++;
            chicks.erase(lb);
        }
    }
    cout<<ans<<endl;
    return 0;
}