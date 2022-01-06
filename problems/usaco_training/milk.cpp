/*
ID: michael419
LANG: C++11
TASK: milk
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
    setIO("milk");
    int n, m, ans=0;
    cin>>n>>m;
    vpi farmers;
    for (int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        farmers.pb({a, b});
    }
    sort(all(farmers));
    trav (i, farmers){
        if (i.s<n){
            n-=i.s;
            ans+=i.f*i.s;
        } else {
            ans+=i.f*n;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}