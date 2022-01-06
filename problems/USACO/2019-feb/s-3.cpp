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

vector<pair<int, bool>> paths[100005];
bool vis[100005], inverted[100005];

void dfs(int x){
	vis[x]=true;
	for (auto &i:paths[x]){
		if (!vis[i.f]) {
			inverted[i.f]=inverted[x]^i.s;
			dfs(i.f);
		} else {
			if (inverted[i.f]!=(inverted[x]^i.s)) {
				cout<<0<<endl;
				exit(0);
			}
		}
	}
}

int main() {
    setIO("revegetate");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		char a;
		int b, c;
		cin>>a>>b>>c;
		paths[c].emplace_back(b, a!='S');
		paths[b].emplace_back(c, a!='S');
	}
	int c=0;
	for (int i=1;i<=n;i++){
		if (!vis[i]) {
			c++;
			dfs(i);
		}
	}
	cout<<1;
	for (int i=0;i<c;i++){
		cout<<0;
	}
	return 0;
}