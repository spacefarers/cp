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

int n, k;
string board[105];
bool vis[105][105];

void gravity(){
	bool ok=true;
	for (int i=0;i<10;i++){
		for (int j=n-1;j>0;j--){
			if (board[j][i]=='0'&&board[j-1][i]!='0') {
				board[j][i]=board[j-1][i];
				board[j-1][i]='0';
				ok=false;
			}
		}
	}
	if (!ok) gravity();
}

vpi to_delete;

void dfs(int x, int y, char num){
	if (vis[x][y]||x<0||y<0||x>=n||y>=10||board[x][y]!=num||board[x][y]=='0') return;
	vis[x][y]=true;
	to_delete.emplace_back(x, y);
	dfs(x+1, y, num);
	dfs(x-1, y, num);
	dfs(x, y+1, num);
	dfs(x, y-1, num);
}

int main() {
    setIO("mooyomooyo");
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>board[i];
	}
	gravity();
	bool ok=true;
	while (ok){
		ok=false;
		memset(vis, false, sizeof vis);
		for (int i=0;i<n;i++){
			for (int j=0;j<10;j++){
				dfs(i, j, board[i][j]);
				if (to_delete.size()>=k) {
					ok=true;
					for (auto &l:to_delete){
						board[l.f][l.s]='0';
					}
				}
				to_delete.clear();
			}
		}
		gravity();
	}
	for (int i=0;i<n;i++){
		cout<<board[i]<<endl;
	}
	return 0;
}

