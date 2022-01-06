#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a, x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

vpl points, list[20010];
ll mod=1e9+7;
array<ll, 2> sums[100005];

void compute(int x){
	for (auto &i : list){
		sort(all(i));
		ll s=0;
		for (auto &j:i) s+=j.f-i.front().f;
		for (int j=0;j<i.size();j++){
			sums[i[j].s][x]=s;
			ll interval=i[j+1].f-i[j].f;
			s+=(2*j-i.size()+2)*interval;
			s%=mod;
		}
	}
}

int main(){
    setIO("triangles");
	ll n;
	cin>>n;
	for (int i=0;i<n;++i){
		ll a, b;
		cin>>a>>b;
		points.pb({a, b});
	}
	for (int i=0;i<n;i++) list[points[i].f+10005].pb({points[i].s, i});
	compute(0);
	for (auto & i : list) i.clear();
	for (int i=0;i<n;i++) list[points[i].s+10005].pb({points[i].f, i});
	compute(1);
	ll ans=0;
	for (auto &i:sums){
		ans+=i[0]*i[1]%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}