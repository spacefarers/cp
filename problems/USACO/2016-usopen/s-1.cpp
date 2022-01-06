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

int n;
vector<ll> x, y;
vector<ll> maxx, maxy;
vector<pair<ll, ll>> cows;
vi pairs;
ll best_ans=0x7fffffff;

void dfs(){
    if (pairs.size()==4){
        ll area=(maxx[pairs[1]]-x[pairs[0]])*(maxy[pairs[2]]-y[pairs[3]]);
        int c=0;
        trav(i, cows) if (i.f>maxx[pairs[1]]||i.f<x[pairs[0]]||i.s>maxy[pairs[2]]||i.s<y[pairs[3]]) c++;
        if (c<=3) best_ans=min(best_ans, abs(area));
        return;
    }
    for (int i=0;i<=3;i++){
        pairs.pb(i);
        dfs();
        pairs.pop_back();
    }
}

int main() {
    setIO("reduce");
    cin>>n;
    for (int i=0;i<n;i++){
        ll a, b;
        cin>>a>>b;
        x.pb(a);
        y.pb(b);
        cows.emplace_back(a, b);
    }
    sort(all(x));
    sort(all(y));
    for (int i=n-1;i>=n-4;i--) maxx.pb(x[i]);
    for (int i=n-1;i>=n-4;i--) maxy.pb(y[i]);
    dfs();
    cout<<best_ans<<endl;
    return 0;
}