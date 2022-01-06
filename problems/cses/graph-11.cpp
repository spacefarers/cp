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

ll dist[100005], dist2[100005];

void dijkstra(int start, ll dist1[100005], vpl paths[100005]){
	priority_queue<pl, vpl, greater<pl>> q;
	memset(dist1, 0x3f, sizeof dist);
	dist1[start]=0;
	q.push({0, start});
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f>dist1[u.s]) continue;
		trav(i, paths[u.s]){
			if (dist1[i.f]>dist1[u.s]+i.s){
				dist1[i.f]=dist1[u.s]+i.s;
				q.push({dist1[i.f], i.f});
			}
		}
	}
}

int main() {
//    setIO("");
	vpl paths[100005], paths2[100005];
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		paths[a].pb({b, c});
		paths2[b].pb({a, c});
	}
	dijkstra(1, dist, paths);
	dijkstra(n, dist2, paths2);
	ll best_ans=dist[n];
	for (int i=0;i<n;++i){
		trav(k, paths[i]){
			best_ans=min(best_ans, k.s/2+dist[i]+dist2[k.f]);
		}
	}
	cout<<best_ans<<endl;
	return 0;
}

