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

ll income[100005], ans[100005], mod=1e9+7;
vi edge[100005];

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		edge[a].pb(b);
		++income[b];
	}
	stack<int> ss;
	for (int i=2;i<=n;++i){
		if (income[i]==0) ss.push(i);
	}
	while (!ss.empty()){
		int u=ss.top();
		ss.pop();
		trav(j, edge[u]){
			--income[j];
			if (income[j]==0) ss.push(j);
		}
	}
	ss.push(1);
	ans[1]=1;
	while (!ss.empty()){
		int u=ss.top();
		ss.pop();
		trav(j, edge[u]){
			--income[j];
			ans[j]+=ans[u];
			ans[j]%=mod;
			if (income[j]==0) ss.push(j);
		}
	}
	cout<<ans[n]<<endl;
	return 0;
}

