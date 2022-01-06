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

string maze[1005];
pi start, finish;
pair<int, string> best;
string c_path;
int n, m;
int dist[1005][1005];

void dfs(pi a){
	if (a==finish){
		if (best.f>c_path.size()){
			best={c_path.size(), c_path};
		}
	}
	if (a.f<0||a.s<0||a.f>=n||a.s>=m||maze[a.f][a.s]=='#'||c_path.size()>dist[a.f][a.s]) return;
	dist[a.f][a.s]=c_path.size();
	string orig=c_path;
	c_path+='U';
	dfs({a.f-1, a.s});
	c_path=orig;
	c_path+='D';
	dfs({a.f+1, a.s});
	c_path=orig;
	c_path+='R';
	dfs({a.f, a.s+1});
	c_path=orig;
	c_path+='L';
	dfs({a.f, a.s-1});
	c_path=orig;
}

int main() {
//    setIO("");
	cin>>n>>m;
	best={10000000, "IMPOSSIBLE"};
	memset(dist, 0x7f, sizeof dist);
	for (int i=0;i<n;++i){
		cin>>maze[i];
		for (int j=0;j<m;j++){
			if (maze[i][j]=='A'){
				start={i, j};
			} else if (maze[i][j]=='B'){
				finish={i, j};
			}
		}
	}
	dfs(start);
	if (best.f==10000000) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl<<best.f<<endl<<best.s<<endl;
	}
	return 0;
}

