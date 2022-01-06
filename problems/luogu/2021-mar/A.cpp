#include <iostream>

using namespace std;

#define ll long long

int main(){
	int t;
	cin>>t;
	while (t--){
		ll x, y, k;
		cin>>x>>y>>k;
		if (y==0) swap(x, y);
		if (x==0){
			if (y==0||y>k||k%y) cout<<0<<endl;
			else cout<<1<<endl;
		} else cout<<min(k/x, k/y)<<endl;
	}
}