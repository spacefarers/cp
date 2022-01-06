/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
//    setIO("swap");
    ll n, k, a, b, c, d;
    cin>>n>>k>>a>>b>>c>>d;
    ll ans[105];
    for (ll i=1;i<=n;i++){
        ll x=i, count=0;
        do {
            if (a<=x&&x<=b){
                x=(a+b)-x;
            }
            if (c<=x&&x<=d){
                x=(c+d)-x;
            }
            count++;
        } while (x!=i);
        ll rem=k%count;
        for (int j=1;j<=rem;j++){
            if (a<=x&&x<=b){
                x=(a+b)-x;
            }
            if (c<=x&&x<=d){
                x=(c+d)-x;
            }
        }
        ans[x]=i;
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}