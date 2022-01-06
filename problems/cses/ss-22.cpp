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

ll nums[200005];

int main() {
//    setIO("");
    ll n, ans=0;
    cin>>n;
    map<ll, int> mp;
    mp[0]++;
    ll sum_all=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        sum_all=(sum_all+a%n+n)%n;
        ans+=mp[sum_all];
        mp[sum_all]++;
    }
    cout<<ans<<endl;
    return 0;
}

