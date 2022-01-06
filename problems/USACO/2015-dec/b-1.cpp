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
    setIO("paint");
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans=b-a+d-c;
    if (a<=c&&b>=c&&b<=d) ans-=(b-c);
    else if (a<=c&&b>=d) ans-=(d-c);
    else if (a>=c&&a<=d&&b>=d) ans-=(d-a);
    else if (a>=c&&b<=d) ans-=(b-a);
    cout<<ans<<endl;
    return 0;
}