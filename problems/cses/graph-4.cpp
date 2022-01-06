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

vi paths[100005];
int dist[100005];
int trace[100005];

int main(){
//    setIO("");
	memset(dist, 0x7f, sizeof dist);
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		paths[a].pb(b);
		paths[b].pb(a);
	}
	priority_queue<pi, vpi, greater<pi>> q;
	q.push({1, 1});
	dist[1]=1;
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		trav(i, paths[u.s]){
			if (dist[i]>dist[u.s]+1) {
				dist[i]=dist[u.s]+1;
				trace[i]=u.s;
				q.push({dist[i], i});
			}
		}
	}
	if (dist[n]>1000000) cout<<"IMPOSSIBLE"<<endl;
	else {
		vi ans;
		int target=n;
		while (target!=1){
			ans.pb(target);
			target=trace[target];
		}
		ans.pb(1);
		reverse(all(ans));
		cout<<ans.size()<<endl;
		trav(i, ans) cout<<i<<" ";
	}
	return 0;
}

