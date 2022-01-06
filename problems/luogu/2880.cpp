#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int K=30, log_table[50005], min_st[50005][31], max_st[50005][31];

int main(){
	memset(min_st, 0x3f, sizeof min_st);
	log_table[1]=0;
	for (int i=2;i<=50005;i++){
		log_table[i]=log_table[i/2]+1;
	}
	int n, q;
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>min_st[i][0];
	for (int i=0;i<n;i++) max_st[i][0]=min_st[i][0];
	for (int i=1;i<=K;i++){
		for (int j=0;j+(1<<i)<=n;j++){
			min_st[j][i]=min(min_st[j][i-1], min_st[j+(1<<(i-1))][i-1]);
		}
	}
	for (int i=1;i<=K;i++){
		for (int j=0;j+(1<<i)<=n;j++){
			max_st[j][i]=max(max_st[j][i-1], max_st[j+(1<<(i-1))][i-1]);
		}
	}
	while (q--){
		int L,R;
		cin>>L>>R;
		L--,R--;
		int j=log_table[R-L+1];
		cout<<max(max_st[L][j],max_st[R-(1<<j)+1][j])-min(min_st[L][j],min_st[R-(1<<j)+1][j])<<endl;
	}
}