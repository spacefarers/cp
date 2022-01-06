#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

bool isPrime(ll num){
	for (ll i=2;i*i<=num;i++){
		if (num%i==0) return false;
	}
	return true;
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		cout<<"Case #"<<i<<": ";
		ll x;
		cin>>x;
		ll g=floor(sqrt(double(x)));
		ll up_lim=g+1;
		while (!isPrime(g)) g--;
		while (!isPrime(up_lim)) up_lim++;
		if (up_lim*g<=x){
			cout<<up_lim*g<<endl;
			continue;
		}
		ll down_lim=g-1;
		while (!isPrime(down_lim)) down_lim--;
		cout<<down_lim*g<<endl;
	}
}