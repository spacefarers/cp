//
// Created by spacefarers on 12:43 AM Nov 29 2021.
// Problem: Sum of Divisors

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

ll MOD=1e9+7;

int main(){
	fastio
	ll n;
	cin>>n;
	ll ans=0;
	for (ll i=1;i*i<=n;i++){
		ans+=(i+(n/i)%MOD)*((n/i)%MOD-i+1)/2+((n/i)%MOD-i)*i;
		ans%=MOD;
	}
	cout<<ans<<endl;
}

