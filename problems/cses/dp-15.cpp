#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <unordered_map>
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


int main() {
//    setIO("");
	int n;
	cin>>n;
	map<ll, vpl> times;
	map<ll, ll> dp;
	for (int i=0;i<n;++i){
		ll a, b, c;
		cin>>a>>b>>c;
		times[b].pb({a, c});
	}
	ll last=0;
	trav(i, times){
		auto evs=i.s;
		dp[i.f]=last;
		trav(j, evs){
			auto it=dp.lower_bound(j.f);
			ll c=0;
			if (it!=dp.begin()){
				--it;
				c=(*it).s;
			}
			dp[i.f]=max(dp[i.f], c+j.s);
		}
		last=dp[i.f];
	}
	cout<<last<<endl;
	return 0;
}