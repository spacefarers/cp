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

int father[100005];
pl pos[100005];
pair<pl, pl> ans[100005];

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a);
	int d=find(b);
	father[c]=d;
}

int main() {
    setIO("fenceplan");
	int n, m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>pos[i].f>>pos[i].s;
		father[i]=i;
		ans[i]={{0x7fffffff, -0x7fffffff}, {0x7fffffff, -0x7fffffff}};
	}
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		unionn(a-1, b-1);
	}
	for (int i=0;i<n;i++){
		int u=find(i);
		ans[u].f.f=min(ans[u].f.f, pos[i].f);
		ans[u].s.f=min(ans[u].s.f, pos[i].s);
		ans[u].s.s=max(ans[u].s.s, pos[i].s);
		ans[u].f.s=max(ans[u].f.s, pos[i].f);
	}
	ll f_ans=0x7fffffff;
	for (int i=0;i<n;i++){
		if (father[i]!=i) continue;
		auto u=ans[i];
		f_ans=min(f_ans, 2*(u.f.s-u.f.f+u.s.s-u.s.f));
	}
	cout<<f_ans<<endl;
	return 0;
}

