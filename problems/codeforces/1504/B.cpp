#include <bits/stdc++.h>

using namespace std;

int pre[300005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(pre,0,sizeof pre);
		int n;
		cin>>n;
		string a, b;
		cin>>a>>b;
		for (int i=0;i<n;i++){
			if (a[i]=='1') pre[i]++;
			if (i!=0) pre[i]+=pre[i-1];
		}
		bool flipped=false;
		for (int i=n-1;i>=0;i--){
			if ((a[i]==b[i])^flipped) continue;
			else {
				int num_1=pre[i];
				if (num_1*2!=i+1){
					cout<<"NO"<<endl;
					goto cont;
				}
				flipped=!flipped;
			}
		}
		cout<<"YES"<<endl;
		cont:;
	}
}