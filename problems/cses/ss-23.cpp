#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

vl nums;
ll n, k;

bool validate(ll a){
    ll c=0, ans=1;
    trav (i, nums){
        if (c+i>a) {ans++;c=0;}
        c+=i;
    }
    return ans<=k;
}

int main() {
//    setIO("");
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        nums.pb(a);
    }
    ll x=*max_element(all(nums))-1;
    for (ll a=1e18;a>=1;a/=2){
        while (!validate(x+a)) x+=a;
    }
    cout<<x+1<<endl;
    return 0;
}

