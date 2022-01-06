#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
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

int income[100005];
vi paths[100005];

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		paths[a].pb(b);
		++income[b];
	}
	stack<int> s;
	for (int i=1;i<=n;++i){
		if (income[i]==0) s.push(i);
	}
	vi ans;
	while (!s.empty()){
		int u=s.top();
		s.pop();
		ans.pb(u);
		trav(j, paths[u]){
			if (--income[j]==0){
				s.push(j);
			}
		}
	}
	if (ans.size()<n) cout<<"IMPOSSIBLE"<<endl;
	else {
		trav(j, ans){
			cout<<j<<" ";
		}
	}
	return 0;
}

