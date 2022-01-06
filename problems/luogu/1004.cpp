#include <iostream>

using namespace std;

int dist[10][10][10][10], board[10][10];

int main(){
	int n;
	cin>>n;
	while (true){
		int a, b, c;
		cin>>a>>b>>c;
		if (a==0&&b==0&&c==0) break;
		board[a][b]=c;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			for (int k=1;k<=n;++k){
				for (int l=1;l<=n;++l){
					dist[i][j][k][l]=max(max(dist[i-1][j][k-1][l], dist[i][j-1][k-1][l]), max(dist[i][j-1][k][l-1], dist[i-1][j][k][l-1]))+board[i][j]+board[k][l];
					if (i==k&&j==l) dist[i][j][k][l]-=board[i][j];
				}
			}
		}
	}
	cout<<dist[n][n][n][n]<<endl;
}