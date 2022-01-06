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
ll dist[100005], pre[100005];

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		paths[a].pb(b);
	}
	memset(dist, -0x3f, sizeof dist);
	priority_queue<pi, vpi, greater<pi>> q;
	q.push({1, 1});
	dist[1]=1;
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (dist[u.s]>u.f) continue;
		trav(i, paths[u.s]){
			if (dist[i]<u.f+1){
				dist[i]=u.f+1;
				pre[i]=u.s;
				q.push({dist[i], i});
			}
		}
	}
	if (dist[n]>-1e13) {
		cout<<dist[n]<<endl;
		vi ans;
		while (n!=1){
			ans.pb(n);
			n=pre[n];
		}
		ans.pb(1);
		reverse(all(ans));
		trav(j, ans){
			cout<<j<<" ";
		}
	} else cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

