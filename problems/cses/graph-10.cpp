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

ll dist[2505];
vl paths[2505];
bool vis[2505];

void dfs(int x){
	vis[x]=true;
	trav(i, paths[x]){
		if (!vis[i]) dfs(i);
	}
}

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	vector<pair<ll, pl>> edges;
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		edges.pb({c, {a, b}});
		paths[a].pb(b);
	}
	memset(dist, -0x3f, sizeof dist);
	dist[1]=0;
	for (int i=0;i<n-1;++i){
		trav(edge, edges){
			if (dist[edge.s.f]>-1e12&&dist[edge.s.f]+edge.f>dist[edge.s.s]){
				dist[edge.s.s]=dist[edge.s.f]+edge.f;
			}
		}
	}
	trav(edge, edges){
		if (dist[edge.s.f]>-1e12&&dist[edge.s.s]<dist[edge.s.f]+edge.f) dfs(edge.s.f);
	}
	if (!vis[n]) cout<<dist[n]<<endl;
	else cout<<-1<<endl;
	return 0;
}

