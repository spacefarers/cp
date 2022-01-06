/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
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
    setIO("socdist2");
    int n;
    vector<pair<ll, bool>> a;
    cin>>n;
    a.rsz(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(all(a));
    ll last_a=-1;
    ll last_f=-1;
    ll closest=0x7fffffff;
    trav(i, a){
        if (i.second){
            if (last_f!=-1){
                closest=min(closest, i.first-last_f);
            }
            last_a=i.first;
        } else {
            if (last_a!=-1){
                closest=min(closest, i.first-last_a);
            }
            last_f=i.first;
        }
    }
    ll ans=0;
    last_a=-1;
    trav(i, a){
        if (i.second&&(last_a==-1||i.first-last_a>=closest)){
            ans++;
        }
        last_a=i.first;
    }
    cout<<ans<<endl;
    return 0;
}