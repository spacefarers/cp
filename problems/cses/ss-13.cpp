#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
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

int ans[200005];

bool cmp(pair<pi, int> a, pair<pi, int> b){
    if (a.f.s==b.f.s) return a.f.f<b.f.f;
    return a.f.s<b.f.s;
}

int main() {
//    setIO("");
    int n;
    cin>>n;
    vector<pair<pi, int>> guests;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        guests.pb({{a, b}, i});
    }
    sort(all(guests), cmp);
    set<pi> ss;
    trav(i, guests){
        auto it=ss.lower_bound({i.f.f-1, i.f.s});
        if (it==ss.begin()) ans[i.s]=ss.size();
        else {
            --it;
            ans[i.s]=(*it).s;
            ss.erase(it);
        }
        ss.insert({i.f.s, ans[i.s]});
    }
    cout<<ss.size()<<endl;
    for (int i=0;i<n;i++){
        cout<<ans[i]+1<<" ";
    }
    return 0;
}

