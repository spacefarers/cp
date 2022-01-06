#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <map>
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

vector<pair<pi, int>> bessie, elsie;
vi paths[200005];
int dist[200005];

bool cmp1(pair<pi, int> a, pair<pi, int> b){
    return a.f.s<b.f.s;
}
bool cmp2(pair<pi, int> a, pair<pi, int> b){
    return a.f.f<b.f.f;
}
bool cmp3(pair<pi, int> a, pair<pi, int> b){
    return a.s<b.s;
}

int main() {
    setIO("piepie");
    int n, d;
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        bessie.pb({{a, b}, i});
    }
    for (int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        elsie.pb({{a, b}, i+n});
    }
    sort(all(bessie), cmp1);
    sort(all(elsie), cmp1);
    int be_c=0, el_c=0;
    while (be_c<n&&el_c<n){
        if (bessie[be_c].f.s>elsie[el_c].f.s){el_c++;continue;}
        if (bessie[be_c].f.s+d<elsie[el_c].f.s){be_c++;continue;}
        int backup=el_c;
        while (bessie[be_c].f.s+d>=elsie[el_c].f.s&&el_c<n) {
            paths[elsie[el_c].s].pb(bessie[be_c].s);
            el_c++;
        }
        el_c=backup;
        be_c++;
    }
    sort(all(bessie), cmp2);
    sort(all(elsie), cmp2);
    be_c=0, el_c=0;
    while (be_c<n&&el_c<n){
        if (bessie[be_c].f.f<elsie[el_c].f.f){be_c++;continue;}
        if (bessie[be_c].f.f>elsie[el_c].f.f+d){el_c++;continue;}
        int backup=be_c;
        while (bessie[be_c].f.f<=elsie[el_c].f.f+d&&be_c<n) {
            paths[bessie[be_c].s].pb(elsie[el_c].s);
            be_c++;
        }
        be_c=backup;
        el_c++;
    }
    priority_queue<pi, vpi, greater<pi>> q;
    memset(dist, 0x3f, sizeof(dist));
    sort(all(bessie), cmp3);
    sort(all(elsie), cmp3);
    vi zeros;
    for (int i=0;i<n;i++){
        if (bessie[i].f.s==0) zeros.pb(bessie[i].s);
        if (elsie[i].f.f==0) zeros.pb(elsie[i].s);
    }
    trav (i, zeros){
//        cout<<i<<endl;
        dist[i]=1;
        q.push({1, i});
    }
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        trav (e, paths[u.s]){
            if (dist[e]>dist[u.s]+1){
                dist[e]=dist[u.s]+1;
                q.push({dist[e], e});
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (dist[i]>100000) dist[i]=-1;
        cout<<dist[i]<<endl;
    }
    return 0;
}