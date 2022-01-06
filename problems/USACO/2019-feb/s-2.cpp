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

int dif[1005][1005];

int main() {
    setIO("paintbarn");
	int n, k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		a++;b++;c++;d++;
		dif[a][b]++;
		dif[c][d]++;
		dif[a][d]--;
		dif[c][b]--;
	}
	int ans=0;
	for (int i=1;i<1005;i++){
		for (int j=1;j<1005;j++){
			dif[i][j]+=dif[i][j-1]+dif[i-1][j]-dif[i-1][j-1];
			if (dif[i][j]==k) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

