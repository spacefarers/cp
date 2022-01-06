#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<vector<bool>> permutations;
vector<bool> c_per;

void create_permutes(){
	if (c_per.size()==15){
		permutations.push_back(c_per);
		return;
	}
	c_per.push_back(true);
	create_permutes();
	c_per.pop_back();
	c_per.push_back(false);
	create_permutes();
	c_per.pop_back();
}

ll gcd(ll a, ll b){
	if (b==0) return a;
	return gcd(b, a%b);
}

int main(){
	int n;
	cin>>n;
	vector<ll> inputs(n);
	for (int i=0;i<n;i++){
		cin>>inputs[i];
	}
	vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	ll ans=1e18;
	create_permutes();
	for (auto &i:permutations){
		ll c=1;
		for (int j=0;j<15;j++){
			if (i[j]) c*=primes[j];
		}
		for (auto &j:inputs){
			if (gcd(j, c)==1) goto cont;
		}
		ans=min(ans, c);
		cont:;
	}
	cout<<ans<<endl;
}