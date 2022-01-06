//
// Created by spacefarers on 7:35 PM Nov 24 2021.
// Problem: D. Hot Days

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
	fastio
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	for (int i=0;i<n;i++){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if (a>=b){
			ans+=m*c+d;
			continue;
		}
		ll busLoad=b-a;
		if (m<=busLoad){
			ans+=d;
			continue;
		}
		ll noOther=d+m*c;
		ll allOther=d*((m+busLoad-1)/busLoad);
		ans+=min(noOther,allOther);
	}
	cout<<ans<<endl;
}

