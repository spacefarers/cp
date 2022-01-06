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
bool vis[100005], vvis[100005];
int pre[100005];

void dfs(int a, int from){
	pre[a]=from;
	vvis[a]=true;
	trav(j, paths[a]){
		if (vis[j]&&from!=-1){
			vi ans;
			ans.pb(j);
			while (a!=j){
				ans.pb(a);
				a=pre[a];
			}
			ans.pb(j);
			cout<<ans.size()<<endl;
			reverse(all(ans));
			trav(k, ans){
				cout<<k<<" ";
			}
			exit(0);
		} else {
			vis[j]=true;
			dfs(j, a);
			vis[j]=false;
		}
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
	}
	for (int i=0;i<n;++i){
		if (!vvis[i]) dfs(i, -1);
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}

