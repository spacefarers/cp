#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define f first
#define s second
#define ll long long

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		ll mina=1e18, minb=1e18, suma=0, sumb=0, ans=1e18;
		for (int i=0;i<n;i++){
			ll inp;
			cin>>inp;
			if (i%2==0){
				suma+=inp;
				mina=min(mina, inp);
			} else {
				sumb+=inp;
				minb=min(minb, inp);
			}
			if (i>=1){
				ans=min(ans, suma+mina*(n-int(ceil(double(i+1)/2)))+sumb+minb*(n-(i+1)/2));
			}
		}
		cout<<ans<<endl;
	}
}