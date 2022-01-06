//
// Created by spacefarers on 4:53 PM Dec 20 2021.
// Problem: Problem 3. HILO

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

using namespace std;

int MOD=1e9+7;

ll power(ll x,ll y,ll p){
	ll res=1;
	x=x%p;
	while (y>0){
		if (y&1) res=(res*x)%p;
		y/=2;
		x=(x*x)%p;
	}
	return res;
}

ll modInverse(ll n,ll p){
	return power(n,p-2,p);
}

ll fac[100005];

ll nCrModPFermat(ll n,ll r,ll p){
	if (n<r) return 0;
	if (r==0) return 1;
	return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p;
}

int main(){
	fac[0]=1;
	for (int i=1;i<100005;i++)
		fac[i]=(fac[i-1]*i)%MOD;
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int N,x;
	cin>>N>>x;
	int left_range=x,right_range=N-x;
	ll ans=0;
	for (int i=1;i<=left_range;i++){
		for (int j=1;j<=right_range;j++){
			ll numL=nCrModPFermat(left_range-1,i-1,MOD)*fac[left_range-i];
			ll numH=nCrModPFermat(right_range-1,j-1,MOD)*fac[right_range-j];
//			for (int k=1;k<=min(i,j);k++){
//				ans+=(((power(k+1,i-k+j-k,MOD)%MOD*numL)%MOD*numH)%MOD*k)%MOD;
//			}s
			vector<
		}
	}
	cout<<ans<<endl;
}

