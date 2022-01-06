#include <iostream>
#include <cmath>

using namespace std;

bool board[105][105];

int n, m, t, ans=0;
int r1, c1, r2, c2;

void dfs(int x, int y, int dep){
	if (x<=0||y<=0||x>n||y>m||!board[x][y]||abs(x-r2)+abs(y-c2)>t-dep) return;
	if (dep==t){
		if (x==r2&&y==c2) ans++;
		else return;
	}
	dfs(x+1, y, dep+1);
	dfs(x-1, y, dep+1);
	dfs(x, y+1, dep+1);
	dfs(x, y-1, dep+1);
}

int main(){
	cin>>n>>m>>t;
	for (int i=1;i<=n;++i){
		string a;
		cin>>a;
		for (int j=1;j<=m;++j){
			board[i][j]=a[j-1]=='.';
		}
	}
	cin>>r1>>c1>>r2>>c2;
	dfs(r1, c1, 0);
	cout<<ans<<endl;
}