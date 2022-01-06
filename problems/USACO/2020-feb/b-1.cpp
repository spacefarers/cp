///*
//ID: michael419
//LANG: C++
//TASK:
//*/
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<ll> vi;
//typedef vector<pair<ll,ll>> vpi;
//
//#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
//#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
//#define R0F(i,a) ROF(i,0,a)
//#define trav(a,x) for (auto& a: x)
//
//#define pb push_back
//#define rsz resize
//#define sz(x) ll(x.size())
//#define all(x) begin(x), end(x)
//
//
//void setIO(const string& name) {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    freopen((name+".in").c_str(),"r",stdin);
//    freopen((name+".out").c_str(),"w",stdout);
//}
//
//int main() {
//    setIO("triangles");
//    ll n;
//    cin>>n;
//    vpi a;
//    for (ll i=1;i<=n;i++){
//        ll c, d;
//        cin>>c>>d;
//        a.pb({c, d});
//    }
//    ll ans=0;
//    trav(i, a){
//        ll l=0, w=0;
//        trav(x, a){
//            if (x.first==i.first){
//                w=max(w, abs(x.second-i.second));
//            } else if (x.second==i.second){
//                l=max(l, abs(x.first-i.first));
//            }
//        }
////        cout<<l<<" "<<w;
//        ans=max(ans, l*w);
//    }
//    cout<<ans<<endl;
//    return 0;
//}


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

int n, maxes_x[20005], mins_x[20005], maxes_y[20005], mins_y[20005], b, c;
vpi a;

int main() {
//    setIO("triangles");
    cin>>n;
    memset(maxes_x, -0x7f, sizeof(maxes_x));
    memset(maxes_y, -0x7f, sizeof(maxes_y));
    memset(mins_x, 0x7f, sizeof(mins_x));
    memset(mins_y, 0x7f, sizeof(mins_y));
    for (int i=1;i<=n;i++){
        cin>>b>>c;
        maxes_x[c+10002]=max(maxes_x[c+10002], b);
        mins_x[c+10002]=min(mins_x[c+10002], b);
        maxes_y[b+10002]=max(maxes_y[b+10002], c);
        mins_y[b+10002]=min(mins_y[b+10002], c);
        a.pb({b, c});
    }
    int ans=0;
    trav(i, a){
        int max_x=max(abs(maxes_x[i.second+10002]-i.first), abs(mins_x[i.second+10002]-i.first));
        int max_y=max(abs(maxes_y[i.first+10002]-i.second), abs(mins_y[i.first+10002]-i.second));
//        cout<<i.first<<" "<<i.second<<" "<<max_x<<" "<<max_y<<endl;
        ans=max(ans, max_x*max_y);
    }
    cout<<ans<<endl;
    return 0;
}