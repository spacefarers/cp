#include <iostream>

using namespace std;

int sums_less[505][505], board[505][505], sums_exact[505][505], closest_100[505][505], closest_less[505][505];
int N;

bool valid(int a, int b, int c, int d){
	if (a<=0||b<=0||c<=0||d<=0||a>N||b>N||c>N||d>N) return false;
	int x=sums_less[a][b]-sums_less[c-1][b]-sums_less[a][d-1]+sums_less[c-1][d-1];
	int y=sums_exact[a][b]-sums_exact[c-1][b]-sums_exact[a][d-1]+sums_exact[c-1][d-1];
	return y>0&&x==0;
}

int main(){
	cin>>N;
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			cin>>board[i][j];
//			if (board[i][j]==100){
//				sums_exact[i][j]++;
//			} else if (board[i][j]<100){
//				sums_less[i][j]++;
//			}
		}
	}
//	for (int i=1;i<=N;i++){
//		for (int j=1;j<=N;j++){
//			sums_less[i][j]+=(sums_less[i][j-1]+sums_less[i-1][j]-sums_less[i-1][j-1]);
//			sums_exact[i][j]+=(sums_exact[i][j-1]+sums_exact[i-1][j]-sums_exact[i-1][j-1]);
//		}
//	}
	for (int i=1;i<=N;i++){
		int close_100=-1, close_less=-1;
		for (int j=1;j<=N;j++){
			if (board[i][j]==100) close_100=j;
			if (board[i][j]<100) close_less=j;
			closest_100[i][j]=close_100;
			closest_less[i][j]=close_less;
		}
	}
	long long ans=0;
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (board[i][j]<100) continue;
			int left=1, right=-1;
			for (int k=i;k>=1;k--){
				left=max(left, closest_less[k][j]+1);
				right=max(right, closest_100[k][j]);
				if (right<left) continue;
				ans+=(right-left+1);
			}
		}
	}
	cout<<ans<<endl;
}