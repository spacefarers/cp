#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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

map<pi, int> grid;

int main() {
    setIO("mowing");
    int n;
    cin>>n;
    int ans=0x7fffffff, t=0;
    pi c={510, 510};
    for (int i=0;i<n;i++){
        char a;
        int b;
        cin>>a>>b;
        for (int j=0;j<b;j++){
            t++;
            if (a=='N'){
                c.f--;
            } else if (a=='E'){
                c.s++;
            } else if (a=='W'){
                c.s--;
            } else{
                c.f++;
            }
            if (grid[c]!=0){
                ans=min(ans, t-grid[c]);
            }
            grid[c]=t;
        }
    }
    if (ans>10000) ans=-1;
    cout<<ans<<endl;
    return 0;
}