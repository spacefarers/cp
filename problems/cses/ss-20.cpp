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

int nums[200005];

int main() {
//    setIO("");
    int n, m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        nums[i]=nums[i-1]+a;
    }
    ll l=0, r=1, ans=0;
    while (r<=n){
        if (nums[r]-nums[l]==m){
            ans++; r++; l++;
        } else if (nums[r]-nums[l]<m) r++;
        else l++;
    }
    cout<<ans<<endl;
    return 0;
}

