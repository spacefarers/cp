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

vpi times;

int main() {
    setIO("cowqueue");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        times.pb({a, b});
    }
    sort(all(times));
    int c_time=0;
    trav (i, times){
        c_time=max(c_time, i.first)+i.second;
    }
    cout<<c_time<<endl;
    return 0;
}