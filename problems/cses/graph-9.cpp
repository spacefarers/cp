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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a, x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

ll dist[505][505];

int main(){
//    setIO("");
	int n, m, q;
	cin>>n>>m>>q;
	for (int i=0;i<=n;++i){
		for (int j=0;j<=n;++j){
			dist[i][j]=1e13;
		}
		dist[i][i]=0;
	}
	for (int i=0;i<m;++i){
		ll a, b, c;
		cin>>a>>b>>c;
		dist[a][b]=min(c, dist[a][b]);
		dist[b][a]=min(c, dist[b][a]);
	}
	for (int k=1;k<=n;++k){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=n;++j){
				if (dist[i][j]>dist[i][k]+dist[k][j]) {
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	for (int i=0;i<q;++i){
		int a, b;
		cin>>a>>b;
		if (dist[a][b]>1e12) dist[a][b]=-1;
		cout<<dist[a][b]<<endl;
	}
	return 0;
}

