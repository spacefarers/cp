//
// Created by spacefarers on 1:18 AM Nov 29 2021.
// Problem: Divisor Analysis

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

int MOD=1e9+7;

int primes[100005],pow[100005];

ll modpow(int x,int n){
	if (n==0) return 1%MOD;
	ll u=modpow(x,n/2);
	u=(u*u)%MOD;
	if (n%2==1) u=(u*x)%MOD;
	return u;
}

int main(){
	fastio
	int n;
	cin>>n;
	ll numDiv=0,sumDiv=1,prodDiv=0;
	for (int i=0;i<n;i++){
		cin>>primes[i]>>pow[i];
		numDiv*=(pow[i]+1);
		numDiv%=MOD;
	}
	cout<<numDiv<<" ";
	for (int i=0;i<n;i++){
		(modpow(primes[i],pow[i])-1)/(primes[i]-1);
	}
}

