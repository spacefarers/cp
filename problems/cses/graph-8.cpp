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

vpi paths[100005];
ll dist[100005];

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		paths[a].pb({b, c});
	}
	priority_queue<pl, vpl, greater<pl>> q;
	q.push({0, 1});
	memset(dist, 0x7f, sizeof dist);
	dist[1]=0;
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f>dist[u.s]) continue;
		trav(i, paths[u.s]){
			if (dist[i.f]>dist[u.s]+i.s){
				dist[i.f]=dist[u.s]+i.s;
				q.push({dist[i.f], i.f});
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}

