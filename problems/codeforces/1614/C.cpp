//
// Created by michaelyang on 11:54 PM Dec 28 2021.
// Problem: C. Divan and bitwise operations

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=1e5+5;

ll power(ll x,ll y){
	ll res=1;
	x=x%MOD;
	while (y>0){
		if (y&1) res=(res*x)%MOD;
		y/=2;
		x=(x*x)%MOD;
	}
	return res;
}

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		int n,m;
		cin>>n>>m;
		int tot=0;
		for (int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			tot|=c;
		}
		tot=tot*power(2,n-1)%MOD;
		cout<<tot<<endl;
	}
}