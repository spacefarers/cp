#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

int mp[200005];

int main() {
//    setIO("");
    int n, x;
    cin>>n>>x;
    vi nums1;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums1.pb(a);
    }
    sort(all(nums1));
    ll ans=0;
    for (int i=0, j=nums1.size()-1;i<j;){
        while (i<j&&nums1[i]+nums1[j]>x){
            --j;
        }
        if (i>=j) break;
        ans++;
        i++;j--;
    }
    cout<<n-ans<<endl;
    return 0;
}