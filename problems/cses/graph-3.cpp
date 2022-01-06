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

int find(int a){
	if (father[a]!=a) father[a]=find(father[a]);
	return father[a];
}

void unionn(int a, int b){
	int c=find(a);
	int d=find(b);
	father[c]=d;
}

int main() {
//    setIO("");
	int n, m;
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		father[i]=i;
	}
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		unionn(a, b);
	}
	vi ans;
	for (int i=1;i<=n;i++){
		if (father[i]==i) ans.pb(i);
	}
	cout<<ans.size()-1<<endl;
	for (int i=0;i<ans.size()-1;i++){
		cout<<ans[i]<<" "<<ans[i+1]<<endl;
	}
	return 0;
}

