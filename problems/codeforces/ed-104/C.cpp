#include <iostream>

using namespace std;

int ans[105][105];

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		for (int i=1;i<=n/2;i++){
			if (n%2==0&&i==n/2){
				for (int j=0;j<n/2;j++){
					ans[j][j+i]=0;
				}
				continue;
			}
			for (int j=0;j<n;j++){
				int x=j;
				int y=(j+i)%n;
				if (x>y) swap(x, y);
				ans[x][y]=(j+i>=n)?1:-1;
			}
		}
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				cout<<ans[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}