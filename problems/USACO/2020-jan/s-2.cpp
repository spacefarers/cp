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
    setIO("loan");
    ll n, k, m;
    cin>>n>>k>>m;
//    二分搜索
    ll left=1, right=n;
    while (left<right){
        ll mid=(left+right+1)/2, g=0;
        for (ll i=0;i<k;){
            ll y=(n-g)/mid;
            if (m>=y){
                g+=(k-i)*m;
                break;
            }
            ll a=(n-g)/y-mid+1;
            if (a<=k-i) {
                g += a * y;
                i += a;
            } else {
                g+=(k-i)*y;
                i=k;
            }
        }
//        cout<<mid<<" "<<left<<" "<<right<<" "<<n-g<<endl;
        if (g<n){
            right=mid-1;
        } else {
            left=mid;
        }
    }
    cout<<left<<endl;
    return 0;
}