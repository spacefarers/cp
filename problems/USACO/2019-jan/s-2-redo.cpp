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

bool board[1005][1005], vis[1005][1005];
int n;
pi ans, c;

void dfs(int x, int y){
	if (vis[x][y]||x<=0||y<=0||x>n||y>n||!board[x][y]) return;
	vis[x][y]=true;
	c.f++;
	int peri=0;
	if (!board[x-1][y]) peri++;
	if (!board[x+1][y]) peri++;
	if (!board[x][y+1]) peri++;
	if (!board[x][y-1]) peri++;
	c.s+=peri;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}

int main() {
    setIO("perimeter");
	cin>>n;
	for (int i=1;i<=n;i++){
		string a;
		cin>>a;
		for (int j=1;j<=n;j++){
			board[i][j]=a[j-1]=='#';
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			c={0, 0};
			dfs(i, j);
			if (c.f>ans.f||(c.f==ans.f&&c.s<ans.s)) ans=c;
		}
	}
	cout<<ans.f<<" "<<ans.s<<endl;
	return 0;
}

