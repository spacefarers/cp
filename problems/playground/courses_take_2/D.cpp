#include <iostream>

using namespace std;
#define ll long long

ll c1[50005], n, c2[50005];

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int v, ll c[50005]) {
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=v;
}

ll getSum(int x, const ll c[50005]) {
	ll ans=0;
	for(int i=x; i>0; i-=lowbit(i))
		ans+=c[i];
	return ans;
}

int main(){
	int m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		if (a==1) {
			update(b,1,c1);
			update(c,1,c2);
		} else {
			cout<<getSum(c, c1)-getSum(b-1, c2)<<endl;
		}
	}
}