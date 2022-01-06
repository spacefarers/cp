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

int n, m, ans=0;
string board[1005];
bool visited[1005][1005];

void dfs(int x, int y){
	if (x<0||y<0||x>=n||y>=m||board[x][y]=='#') return;
	if (visited[x][y]) return;
	visited[x][y]=true;
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
}

int main() {
//    setIO("");
	cin>>n>>m;
	for (int i=0;i<n;++i){
		cin>>board[i];
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (!visited[i][j]&&board[i][j]=='.') {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}