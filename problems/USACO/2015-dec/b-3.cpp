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

bool sicked[100], counted[100];

int main() {
    setIO("badmilk");
    int n, m, d, S;
    cin>>n>>m>>d>>S;
    vector<pair<int, pi>> log;
    vpi sick;
    for (int i=0;i<d;i++){
        int p, M, t;
        cin>>p>>M>>t;
        log.pb({t, {p, M}});
    }
    for (int i=0;i<S;i++){
        int a, b;
        cin>>a>>b;
        sick.pb({a, b});
    }
    sort(all(log));
    int ans=0;
    for (int i=1;i<=m;i++){
        bool counts=true;
        memset(sicked, false, sizeof sicked);
        int c_ans=0;
        trav(j, log){
            if (j.s.s!=i) continue;
            trav(s, sick){
                if (sicked[s.f]) continue;
                if (!sicked[s.f]&&s.s<=j.f) counts=false;
            }
            if (!sicked[j.s.f]) {
                sicked[j.s.f]=true;
                c_ans++;
            }
        }
        if (counts) ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}