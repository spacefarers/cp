#include <iostream>

using namespace std;

#define ll long long

ll c[1000005], N;

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int v) {
	for(int i=x;i<=N;i+=lowbit(i))
		c[i]+=v;
}

ll getSum(int x) {
	ll ans=0;
	for(int i=x; i>0; i-=lowbit(i))
		ans+=c[i];
	return ans;
}

int main(){
	int q;
	cin>>N>>q;
	for (int i=1;i<=N;i++){
		int a;
		cin>>a;
		update(i, a);
	}
	for (int i=0;i<q;i++){
		int a, b, ce;
		cin>>a>>b>>ce;
		if (a==1){
			update(b, ce);
		} else {
			cout<<getSum(ce)-getSum(b-1)<<endl;
		}
	}
}