#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long

int prime_cnts[20000005];

void SieveOfEratosthenes(int num){
	for (int i=2;i<=num;i++){
		if (prime_cnts[i]==0) {
			for (int j=i*2;j<=num;j+=i){
                prime_cnts[j]++;
            }
			prime_cnts[i]++;
		}
	}
}

vector<ll> factors(ll x){
	vector<ll> result;
	ll i=1;
	while (i*i<=x){
		if (x%i==0) {
			result.push_back(i);
			if (x/i!=i) {
				result.push_back(x/i);
			}
		}
		i++;
	}
	return result;
}

int main(){
	SieveOfEratosthenes(20000000);
	int t;
	cin>>t;
	while (t--){
		ll c,d,x;
		cin>>c>>d>>x;
		ll ans=0;
		vector<ll> factors_of_x=factors(x);
		vector<ll> workings;
		for (auto &i:factors_of_x){
			if (c<=i+d&&(i+d)%c==0) {
				workings.push_back(x/i);
			}
		}
		for (auto &i:workings){
			ll val=(x+i*d)/(i*c);
			int prime_count=prime_cnts[val];
			ll c_ans=1;
			for (int j=0;j<prime_count;j++){
				c_ans*=2;
			}
			ans+=c_ans;
		}
		cout<<ans<<endl;
	}
}