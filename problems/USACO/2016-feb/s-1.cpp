#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
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

int main() {
    setIO("cbarn");
    int n;
    cin>>n;
    vi nums;
    nums.rsz(n);
    int c=0;
    for (int i=0;i<n;i++){
        cin>>nums[i];
        c=max(0, c+nums[i]-1);
    }
    ll found, ans=0;
    for (int i=0;i<n;i++){
        if (c==0) found=i;
        c=max(0, c+nums[i]-1);
    }
    vi q;
    c=0;
    for (int i=found;;i++){
        int u=i%n;
        if (u==found&&u!=i) break;
        for(int j=0;j<nums[u];j++) q.pb(i);
        ans+=pow(i-q[c++], 2);
    }
    cout<<ans<<endl;
    return 0;
}