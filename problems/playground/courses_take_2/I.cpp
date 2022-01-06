#include <iostream>

using namespace std;

long long f[205][205], f2[205][205];
//f[i][j][k] a的前i个字符中，已选了j个字符，用了k个子串的方案数
//		f2[i][j][k] 记录使用第i个字符的方案数
int main(){
	int a, b, k;
	cin>>a>>b>>k;
	string A, B;
	cin>>A>>B;
	f[0][0]=1;
	for (int i=1;i<=a;i++){
		for (int j=b;j>0;j--){
			for (int l=k;l>0;l--){
				if (A[i-1]==B[j-1]) f2[j][l]=f2[j-1][l]+f[j-1][l-1];
				else f2[j][l]=0;
				f[j][l]+=f2[j][l];
				f2[j][l]%=1000000007;
				f[j][l]%=1000000007;
			}
		}
	}
	cout<<f[b][k]<<endl;
}