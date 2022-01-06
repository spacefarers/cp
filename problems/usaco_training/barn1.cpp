/*
ID: michael419
LANG: C++11
TASK:barn1
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
    setIO("barn1");
    int m, s, c;
    cin>>m>>s>>c;
    vi stalls;
    vpi dists;
    for (int i=0;i<c;i++){
        int a;
        cin>>a;
        stalls.pb(a);
    }
    sort(all(stalls));
    for (int i=0;i<stalls.size()-1;i++){
        dists.pb({stalls[i+1]-stalls[i], i});
    }
    int backup=s;
    s-=(stalls[c-1]-stalls[0]+1);
    sort(all(dists), greater<pi>());
    for (int i=0;i<m-1&&i<dists.size();i++){
        s+=(dists[i].f-1);
    }
    cout<<backup-s<<endl;
    return 0;
}
