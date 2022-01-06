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

int main() {
    setIO("mountains");
	int n;
	cin>>n;
	vpl points;
	for (int i=0;i<n;i++){
		ll a, b;
		cin>>a>>b;
		points.emplace_back(b-a, a+b);
	}
	sort(all(points), greater<pi>());
	ll max_pos=-1, ans=0;
	for (auto &i:points){
		if (i.s<=max_pos) ans++;
		max_pos=max(max_pos, i.s);
	}
	cout<<n-ans<<endl;
	return 0;
}

