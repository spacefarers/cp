//
// Created by spacefarers on 8:25 PM Dec 22 2021.
// Problem: Problem 3. Exercise

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int MOD;

ll power(ll x,ll y,ll m){
	if (y==0) return 1;
	ll p=power(x,y/2,m)%m;
	p=(p*p)%m;
	return (y%2==0)?p:(x*p)%m;
}


bool prime[10005];
vector<int> primes;
ll dp[1500][10005];

void SieveOfEratosthenes(int n){
	memset(prime,true,sizeof(prime));

	for (int p=2;p*p<=n;p++){
		if (prime[p]){
			for (int i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
}
int n;

void setIO(const string&name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("exercise");
	cin>>n>>MOD;
	SieveOfEratosthenes(n);
	for (int i=2;i<=n;i++){
		if (prime[i]) primes.push_back(i);
	}
	for (int i=0;i<=n;i++){
		dp[0][i]=1;
	}
	for (int i=1;i<=primes.size();i++){
		for (int j=0;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			int c=primes[i-1];
			while (c<=j){
				dp[i][j]+=dp[i-1][j-c]*c;
				dp[i][j]%=MOD;
				c*=primes[i-1];
			}
		}
	}
	cout<<dp[primes.size()][n]<<endl;
}

