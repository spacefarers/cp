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
//    setIO("");
	int t;
	cin>>t;
	while (t--){
		int n, k;
		cin>>n>>k;
		vpi levels;
		for (int i=0;i<n;++i){
			int a;
			cin>>a;
			levels.pb({a, });
		}
		pi prev={levels[0], levels[0]+k};
		bool ok=true;
		for (int i=1;i<n-1;++i){
			if (prev.f-levels[i]>=k||levels[i]-prev.s>=k) ok=false;
			prev={levels[i], levels[i]+k};
		}

	}
	return 0;
}

