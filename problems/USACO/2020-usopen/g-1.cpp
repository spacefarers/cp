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

int main() {
    setIO("haircut");
    int n;
    cin>>n;
    vpl nums(n);
    vl l;
    for (int i=0;i<n;i++){
        cin>>nums[i].f;
        nums[i].s=i;
        l.pb(i);
    }
    sort(all(nums));
    ll ans=0, counter=0;
    for (int i=0;i<n;i++){
        cout<<ans<<endl;
        while (nums[counter].f==i){
            auto hair=nums[counter++];
            auto ind=lower_bound(all(l), hair.s)-l.begin();
            ans+=ind;
            l.erase(l.begin()+ind);
        }
    }
    return 0;
}

