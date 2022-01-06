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
#include <algorithm>

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
int n;
vector<ll> sums[100005];
vpi points[20011], p;
const int mod=1e9+7;

void make_list(){
    for (int i=0;i<=20010;i++){
        if (!points[i].empty()){
            sort(all(points[i]));
            ll s=0;
            for (int j=0;j<sz(points[i]);j++){
                s+=(points[i][j].first-points[i][0].first);
            }
            for (int j=0;j<sz(points[i]);j++){
                if (j!=0) s+=(2*j-sz(points[i]))*(points[i][j].first-points[i][j-1].first);
                sums[points[i][j].second].pb(s);
            }
        }
    }
}
int main() {
    setIO("triangles");
    cin>>n;
    p.rsz(n);
    for (int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    for (int i=0;i<p.size();i++){
        points[p[i].first+10005].pb({p[i].second, i});
    }
    make_list();
    for (int i=0;i<=20010;i++) points[i].clear();
    for (int i=0;i<p.size();i++){
        points[p[i].second+10005].pb({p[i].first, i});
    }
    make_list();
    ll ans=0;
    for (int i=0;i<n;i++){
        if (!sums[i].empty()&&sz(sums[i])==2){
            ans+=(sums[i][0]*sums[i][1]);
        }
    }
    cout<<ans%mod<<endl;
    return 0;
}