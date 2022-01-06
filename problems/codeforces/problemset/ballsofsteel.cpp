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
//    setIO("");
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int n, k;
        vpi points;
        bool ok=false, ook;
        cin>>n>>k;
        for (int j=0;j<n;j++){
            int c, d;
            cin>>c>>d;
            points.pb({c, d});
        }
        trav (j, points){
            ook=true;
            trav (u, points){
                if (abs(j.f-u.f)+abs(j.s-u.s)>k) ook=false;
            }
            if (ook) ok=true;
        }
        if (ok) cout<<1<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}