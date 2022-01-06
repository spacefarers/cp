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
    setIO("balancing");
    int n;
    cin>>n;
    vpi cows;
    vi y_values;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        y_values.pb(b);
        cows.pb({a, b});
    }
    sort(all(y_values));
    sort(all(cows));
    ll cow_pos[4];
    ll best=0x7fffffff;
    trav(i, y_values){
        int u=i-1;
        memset(cow_pos, 0, sizeof cow_pos);
        trav(j, cows){
            if (j.s>u) cow_pos[0]++;
            else cow_pos[3]++;
        }
        ll x_value=cows[0].f-1;
        trav(j, cows){
            if (x_value<j.f) {
                x_value=j.f+1;
                ll c=0;
                trav(k, cow_pos) c=max(c, k);
                best=min(best, c);
            }
            if (j.s>u) {
                cow_pos[0]--;
                cow_pos[1]++;
            } else {
                cow_pos[3]--;
                cow_pos[2]++;
            }
        }
    }
    cout<<best<<endl;
    return 0;
}