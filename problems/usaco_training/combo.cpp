/*
ID: michael419
LANG: C++11
TASK: combo
*/

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
    setIO("combo");
    int n, a, b, c, d, e, g, ans=0;
    cin>>n>>a>>b>>c>>d>>e>>g;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                bool master_ok=true, farmer_ok=true;
                if (abs(i-a)>2&&abs(i-n-a)>2&&abs(i+n-a)>2) farmer_ok=false;
                if (abs(i-d)>2&&abs(i-n-d)>2&&abs(i+n-d)>2) master_ok=false;
                if (abs(j-b)>2&&abs(j-n-b)>2&&abs(j+n-b)>2) farmer_ok=false;
                if (abs(j-e)>2&&abs(j-n-e)>2&&abs(j+n-e)>2) master_ok=false;
                if (abs(k-c)>2&&abs(k-n-c)>2&&abs(k+n-c)>2) farmer_ok=false;
                if (abs(k-g)>2&&abs(k-n-g)>2&&abs(k+n-g)>2) master_ok=false;
                if (farmer_ok||master_ok){
//                    cout<<i<<" "<<j<<" "<<k<<endl;
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}