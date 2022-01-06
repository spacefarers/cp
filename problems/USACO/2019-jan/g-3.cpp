#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <unordered_set>

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

ll trace[10005], cows[10005], dist[10005], traced[10005];
vpl paths[10005];


int main() {
    setIO("shortcut");
	memset(dist, 0x3f, sizeof dist);
	int n, m, t;
	cin>>n>>m>>t;
	for (int i=1;i<=n;i++){
		cin>>cows[i];
		trace[i]=i;
	}
	for (int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		paths[a].pb({b, c});
		paths[b].pb({a, c});
	}
	priority_queue<pl, vpl, greater<pl>> q;
	q.push({0, 1});
	dist[1]=0;
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (dist[u.s]<u.f) continue;
		for (auto &i:paths[u.s]){
			if (dist[i.f]>dist[u.s]+i.s||(dist[i.f]==dist[u.s]+i.s&&u.s<trace[i.f])){
				dist[i.f]=dist[u.s]+i.s;
				if (trace[i.f]!=i.f) traced[trace[i.f]]--;
				trace[i.f]=u.s;
				traced[u.s]++;
				q.push({dist[i.f], i.f});
			}
		}
	}
	stack<ll> sss;
	for (int i=1;i<=n;i++){
		if (traced[i]==0) sss.push(i);
	}
	while (!sss.empty()){
		ll u=sss.top();
		sss.pop();
		cows[trace[u]]+=cows[u];
		traced[trace[u]]--;
		if (traced[trace[u]]==0){
			sss.push(trace[u]);
		}
	}
	ll best=0;
	for (int i=1;i<=n;i++){
		best=max(best, cows[i]*(dist[i]-t));
	}
	cout<<best<<endl;
	return 0;
}