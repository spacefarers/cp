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
ll dist[100005], pre[100005];

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		paths[a].pb({b, c});
	}
	for (int i=0;i<=n;++i){
		pre[i]=1;
	}
	priority_queue<pi, vpi, greater<pi>> q;
	q.push({0, 1});
	memset(dist, 0x3f, sizeof dist);
	dist[1]=0;
	pair<pl, pl> best_n={{0x7fffffff, 0}, {0, 0}};
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f>dist[u.s]) continue;
		trav(j, paths[u.s]){
			if (dist[j.f]>=u.f+j.s) pre[j.f]=u.s;
			if (dist[j.f]>u.f+j.s){
				dist[j.f]=u.f+j.s;
				q.push({dist[j.f], j.f});
			}
			if (j.f==n){
				ll c=n, cnt=0;
				while (c!=1){
					c=pre[c];
					cnt++;
				}
				if (u.f+j.s<best_n.f.f) best_n={{u.f+j.s, 1}, {cnt, cnt}};
				else if (u.f+j.s==best_n.f.f) {
					best_n.f.s++;
					best_n.s.f=min(best_n.s.f, cnt);
					best_n.s.s=max(best_n.s.s, cnt);
				}
			}
		}
	}
	cout<<best_n.f.f<<" "<<best_n.f.s<<" "<<best_n.s.f<<" "<<best_n.s.s<<endl;
	return 0;
}