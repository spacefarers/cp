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

int n, m, k;
int orders[35][100005], ans[100005], temp[100005];

ll poww(int a, int b){
	ll c=1;
	for (int i=0;i<b;++i){
		c*=a;
	}
	return c;
}

void execute(int x){
	for (int i=1;i<=n;++i){
		temp[i]=ans[orders[x][i]];
	}
	for (int i=1;i<=n;++i){
		ans[i]=temp[i];
	}
}

int main() {
    setIO("swap");
	cin>>n>>m>>k;
	for (int i=1;i<=n;++i){
		orders[0][i]=i;
		ans[i]=i;
	}
	for (int i=0;i<m;++i){
		int a, b;
		cin>>a>>b;
		vi change_list;
		for (int j=a;j<=b;++j){
			change_list.pb(orders[0][j]);
		}
		reverse(all(change_list));
		for (int j=a;j<=b;++j){
			orders[0][j]=change_list[j-a];
		}
	}
	for (int i=1;i<35;++i){
		for (int j=1;j<=n;++j){
			orders[i][j]=orders[i-1][orders[i-1][j]];
		}
	}
	ll t=35;
	while (k>0){
		while (k<poww(2, t)) t--;
		ll times=k/poww(2, t);
		k%=poww(2, t);
		for (int i=0;i<times;++i){
			execute(t);
		}
	}
	for (int i=1;i<=n;++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}