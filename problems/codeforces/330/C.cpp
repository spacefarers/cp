//
// Created by spacefarers on 11:17 AM Nov 22 2021.
// Problem: C. Beautiful Numbers

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

#define f first
#define s second
#define ll long long

using namespace std;

ll MOD=1e9+7;

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

ll nCrModPFermat(ll n,ll r,ll p){
	if (n<r) return 0;
	if (r==0) return 1;
	ll fac[n+1];
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=(fac[i-1]*i)%p;

	return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r],p)%p)%p;
}

vector<int> c;
vector<int> posSums;
int a,b,n;
int mxSum,minSum;

int makeNum(){
	int ans=0;
	for (int i=0;i<c.size();i++){
		ans+=c[i]*(int)pow(10,i);
	}
	return ans;
}

void dfs(){
	if (makeNum()>mxSum) return;
	else if (makeNum()>=minSum){
		posSums.push_back(makeNum());
		return;
	}
	c.push_back(a);
	dfs();
	c.pop_back();
	c.push_back(b);
	dfs();
	c.pop_back();
}

int main(){
	cin>>a>>b>>n;
	mxSum=b*n,minSum=a*n;
	dfs();
	ll ans=0;
	for (auto&i:posSums){
		if ((i-n*a)%(b-a)) continue;
		int numB=(i-n*a)/(b-a);
		ans+=nCrModPFermat(n,numB,MOD);
		ans%=MOD;
	}
	cout<<ans<<endl;
}
