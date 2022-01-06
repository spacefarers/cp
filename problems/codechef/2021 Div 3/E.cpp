#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int sums[1005][1005];
int n, m, k;

bool validate(int x){
	x--;
	for (int i=1;i<=n-x;i++){
		for (int j=1;j<=m-x;j++){
			int left=sums[i+x][j+x]-sums[i-1][j+x]-sums[i+x][j-1]+sums[i-1][j-1];
			if (left<=k) return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin>>T;
	while (T--){
		memset(sums, 0, sizeof sums);
		cin>>n>>m>>k;
		vector<string> board;
		for (int i=0;i<n;i++){
			string a;
			cin>>a;
			board.push_back(a);
		}
		int zeros=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (board[i-1][j-1]=='0') zeros++;
				sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+(board[i-1][j-1]-'0');
			}
		}
		int max_num=floor(sqrt(zeros));
		max_num=min(max_num, n);
		max_num=min(max_num, m);
		int z=0;
		for (int i=max_num;i>=1;i/=2){
			while (validate(i+z)) z+=i;
		}
		z=min(max_num, z);
		cout<<z<<endl;
	}
}