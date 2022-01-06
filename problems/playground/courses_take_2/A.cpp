#include <iostream>
#include <vector>

using namespace std;

#define ll long long

const int MAXN = 1e6 + 10;
ll c[MAXN];
int n=32005;

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int v) {
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=v;
}

ll getSum(int x) {
	ll ans=0;
	for(int i=x; i>0; i-=lowbit(i))
		ans+=c[i];
	return ans;
}

int ans[15005];

int main(){
	int N;
	cin>>N;
	for (int i=0;i<N;i++){
		int x, y;
		cin>>x>>y;
		x++;
		ans[getSum(x)]++;
		update(x, 1);
	}
	for (int i=0;i<N;i++){
		cout<<ans[i]<<endl;
	}
}