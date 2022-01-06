#include <iostream>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if (b==0) return a;
	return gcd(b, a%b);
}

int main(){
	int t;
	cin>>t;
	while (t--){
		ll x;
		cin>>x;
		while (true){
			ll sum_all=0;
			ll bp=x;
			while (x>0){
				sum_all+=x%10;
				x/=10;
			}
			x=bp;
			if (gcd(x, sum_all)!=1) break;
			x++;
		}
		cout<<x<<endl;
	}
}