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

ll ans=0, n, nums[100005], id[100005];

int main() {
    setIO("sort");
    cin>>n;
    for (ll i=0;i<n;i++){
        cin>>nums[i];
        id[i]=i;
    }
    sort(id, id+n, [](ll a, ll b){return nums[a]<nums[b]||(nums[a]==nums[b]&&a<b);});
    for (int i=0;i<n;i++){
        ans=max(ans, id[i]-i);
    }
    cout<<ans+1<<endl;
    return 0;
}