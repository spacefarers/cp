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

vector<pair<ll, pl>> edges;
vl paths[2505];
ll dist[2505];
bool vis[2505];
int pre[2505];

int main(){
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		edges.pb({c, {a, b}});
		paths[a].pb(b);
	}
	int x;
	for (int i=0;i<n-1;++i){
		x=-1;
		trav(k, edges){
			if (dist[k.s.f]<1e15&&dist[k.s.s]>dist[k.s.f]+k.f) {
				pre[k.s.s]=k.s.f;
				dist[k.s.s]=dist[k.s.f]+k.f;
				x=k.s.s;
			}
		}
	}
	if (x==-1) cout<<"NO"<<endl;
	else {
		for (int i=0;i<n;++i){
			x=pre[x];
		}
		vi cycle;
		for (int v=x;;v=pre[v]){
			cycle.pb(v);
			if (v==x&&cycle.size()>1) break;
		}
		reverse(all(cycle));
		cout<<"YES"<<endl;
		trav(k, cycle){
			cout<<k<<" ";
		}
	}
	return 0;
}

