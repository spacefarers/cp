/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
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

int n, m, a, b, c, d;
int path[1005][1005], size[1005][1005], val[1005], s[1005];
priority_queue<pair<double, int>> q;

int main() {
    setIO("pump");
    memset(path, 0x7f, sizeof(path));
    memset(size, 0, sizeof(size));
    memset(val, 0x7f, sizeof(val));
    memset(s, 0, sizeof(s));
    cin>>n>>m;
    F0R(i, m){
        cin>>a>>b>>c>>d;
        path[--a][--b] = c;
        path[b][a] = c;
        size[a][b] = d;
        size[b][a] = d;
    }
    q.push({0, 0});
    s[0] = 10000;
    val[0] = 0;
    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        if (val[e.second]!=0&&e.first!=(double)s[e.second]/(double)val[e.second]) continue;
        F0R(z, n){
            if (z==e.second||path[e.second][z]>=10000) continue;
            double new_val = (double)min(s[e.second], size[e.second][z])/(double)(val[e.second]+path[e.second][z]);
            double previous;
            if (val[z] == 0 || s[z]>=10000){
                previous = 0x7fffffff;
            } else {
                previous = (double)s[z]/(double)val[z];
            }
            if (previous<new_val){
//                cout<<previous<<" "<<z<<endl;
                s[z] =min(s[e.second], size[e.second][z]);
                val[z] =(val[e.second]+path[e.second][z]);
                q.push({new_val, z});
            }
        }
    }
//    F0R(i, n)
//    cout<<s[i]<<" "<<val[i]<<endl;
    cout<<int((double)s[n-1]/(double)val[n-1]*1000000)<<endl;
    return 0;
}
