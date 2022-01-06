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
vi times;
int n, m, c;

bool validate(int x){
	int last_time=times.front(), c2=1, c_cows=0;
	for (auto &i:times){
		if (i-last_time>x||c_cows>=c) {
			c2++;
			last_time=i;
			c_cows=0;
		}
		c_cows++;
	}
	return c2<=m;
}

int main() {
    setIO("convention");
	cin>>n>>m>>c;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		times.pb(a);
	}
	sort(all(times));
	int z=-1;
	for (int i=1e9;i>=1;i/=2){
		while (!validate(z+i)) z+=i;
	}
	cout<<z+1<<endl;
	return 0;
}