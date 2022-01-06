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

int cows[50005];
vi nums[7];
int n;


int main() {
    setIO("div7");
    cin>>n;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        cows[i]=(cows[i-1]+a)%7;
        if (nums[cows[i]].size()>=2) nums[cows[i]].pop_back();
        nums[cows[i]].pb(i);
    }
    int ans=0;
    for (int i=0;i<=6;i++){
        if (nums[i].size()<2) continue;
        ans=max(ans, nums[i][1]-nums[i][0]);
    }
    cout<<ans<<endl;
    return 0;
}