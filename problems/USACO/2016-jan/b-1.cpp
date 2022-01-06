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

int ans[3];

int main() {
    setIO("promote");
    int a, b, c, d, e, i, g, h;
    cin>>a>>b>>c>>d>>e>>g>>h>>i;
    int carry=0;
    carry+=i-h;
    carry=max(carry, 0);
    ans[2]=carry;
    carry+=g-e;
    carry=max(carry, 0);
    ans[1]=carry;
    carry+=d-c;
    carry=max(carry, 0);
    ans[0]=carry;
    for (int j=0;j<=2;j++){
        cout<<ans[j]<<endl;
    }
    return 0;
}