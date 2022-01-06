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

int clocks[2505], depth[2505];
vi adj[2505];

void dfs(int x, int dep, int pre){
	depth[x]=dep;
	for (auto &i:adj[x]){
		if (i!=pre) dfs(i, dep+1, x);
	}
}

int main() {
    setIO("clocktree");
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>clocks[i];
	}
	for (int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0, -1);
	int c=0, d=0, a=0, b=0;
	for (int i=1;i<=n;i++){
		if (depth[i]%2==0) {
			c+=clocks[i];
			a++;
		}
		else {
			d+=clocks[i];
			b++;
		}
	}
	if (c%12==d%12) cout<<n<<endl;
	else if (c%12==(d+1)%12) cout<<a<<endl;
	else if (c%12==(d-1)%12) cout<<b<<endl;
	else cout<<0<<endl;
	return 0;
}

