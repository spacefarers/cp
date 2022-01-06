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

vpl paths[100005];
ll dist[100005][10];

int main() {
//    setIO("");
	int n, m, k;
	cin>>n>>m>>k;
	for (int i=0;i<m;++i){
		ll a, b, c;
		cin>>a>>b>>c;
		paths[a].pb({b, c});
	}
	priority_queue<pl, vpl, greater<pl>> q;
	memset(dist, 0x3f, sizeof dist);
	q.push({0, 1});
	dist[1][0]=0;
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (dist[u.s][k-1]<u.f) continue;
		trav(j, paths[u.s]){
			if (dist[j.f][k-1]>u.f+j.s){
				dist[j.f][k-1]=u.f+j.s;
				q.push({dist[j.f][k-1], j.f});
				sort(dist[j.f], dist[j.f]+k);
			}
		}
	}
	for (int i=0;i<k;++i){
		cout<<dist[n][i]<<" ";
	}
	return 0;
}

