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

bool visited[100005], color[100005];
vi paths[100005];

void dfs(int a, bool c){
	if (visited[a]){
		if (c!=color[a]){
			cout<<"IMPOSSIBLE"<<endl;
			exit(0);
		}
		return;
	}
	visited[a]=true;
	color[a]=c;
	trav(i, paths[a]){
		dfs(i, !c);
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
		if (!visited[i]) dfs(i, true);
	}
	for (int i=1;i<=n;++i){
		if (color[i]) cout<<1<<" ";
		else cout<<2<<" ";
	}
	return 0;
}

