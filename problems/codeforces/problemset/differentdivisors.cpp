#include <iostream>
#include <cmath>

using namespace std;

bool check_prime(int a){
	for (int i=2;i<=sqrt(a);i++){
		if (a%i==0) return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		int d;
		cin>>d;
		int ans1=d+1;
		while (!check_prime(ans1)) ans1++;
		int ans2=ans1+d;
		while (!check_prime(ans2)) ans2++;
		cout<<ans1*ans2<<endl;
	}
}