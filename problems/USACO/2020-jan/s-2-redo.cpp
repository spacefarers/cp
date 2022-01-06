#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

ll n, k, m;

bool validate(ll x){
	ll g=0, c=0;
	while (g<n){
		ll y=(n-g)/x, r=n-g;
		if (y>m) {
			ll a=r/y-x+1;
			c+=a;
			g+=y*a;
		} else return c+ceil((double)(n-g)/m)<=k;
		if (c>k) return false;
	}
	return true;
}

int main() {
    setIO("loan");
	cin>>n>>k>>m;
	ll z=-1;
	for (ll i=1e14;i>=1;i/=2){
		while (validate(i+z)) z+=i;
	}
	cout<<z<<endl;
	return 0;
}