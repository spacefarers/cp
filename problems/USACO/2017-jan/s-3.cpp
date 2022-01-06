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

ll a;
string b;

ll poww(ll x, ll y){
    ll ans=1;
    for (int i=0;i<y;i++){
        ans*=x;
    }
    return ans;
}

int main() {
    setIO("cowcode");
    cin>>b>>a;
    while (a>b.size()){
        ll c=0;
        while (poww(2, c)*b.size()<a){
            c++;
        }
        c--;
        ll val=poww(2, c)*b.size();
        if (a!=val+1)
            a-=val;
        a--;
    }
    cout<<b[a-1]<<endl;
    return 0;
}