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

vi paths[100005];
bool visited[100005];
int trace[100005];

void dfs(int x, int from){
	trace[x]=from;
	visited[x]=true;
	trav(i, paths[x]){
		if (i==from) continue;
		if (visited[i]){
			vi ans;
			ans.pb(i);
			while (x!=i){
				ans.pb(x);
				x=trace[x];
			}
			ans.pb(i);
			cout<<ans.size()<<endl;
			trav (j, ans) cout<<j<<" ";
			exit(0);
		} else dfs(i, x);
	}
}

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		paths[a].pb(b);
		paths[b].pb(a);
	}
	for (int i=1;i<=n;++i){
		if (!visited[i])
			dfs(i, -1);
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}