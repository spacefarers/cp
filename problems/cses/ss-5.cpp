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
    int n;
    cin>>n;
    vpi times;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        times.pb({a, 1});
        times.pb({b, 2});
    }
    sort(all(times));
    int c=0, max_all=0;
    trav(i, times){
        if (i.s==1) c++;
        else c--;
        max_all=max(max_all, c);
    }
    cout<<max_all<<endl;
    return 0;
}