#include <iostream>
#include <cstring>

using namespace std;

#define MAX 200005

long long flavor[MAX], K=30, log_table[MAX], st[MAX][31];

int main(){
	long long n, m;
	cin>>n>>m;
	memset(st, 0x3f, sizeof st);
	log_table[1]=0;
	for (int i=2;i<=MAX;i++){
		log_table[i]=log_table[i/2]+1;
	}
	for (int i=0;i<n;i++){
		long long a,b;
		cin>>a>>b;
		flavor[i]=a;
		st[i][0]=b;
	}
	for (int i=1;i<=K;i++){
		for (int j=0;j+(1<<i)<=n;j++){
			st[j][i]=max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
		}
	}
	long long left=0,right=0, tot_flav=0, ans=2e18;
	for (right=0;right<n;right++){
		tot_flav+=flavor[right];
		if (tot_flav<m) continue;
		while (tot_flav-flavor[left]>=m){
			tot_flav-=flavor[left++];
		}
		long long j=log_table[right-left];
		ans=min(ans, max(st[left][j], st[right-(1<<j)][j]));
	}
	cout<<ans<<endl;
}