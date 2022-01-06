//
// Created by spacefarers on 8:13 PM Nov 24 2021.
// Problem: E. Minimizing Difference

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> nums;
	for (int i=0;i<n;i++){
		ll a;
		cin>>a;
		nums.push_back(a);
	}
	sort(nums.begin(),nums.end());
	ll ans=nums.back()-nums.front();
	int limFront=(n-1)/2,limBack=n/2;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
	for (int i=1;i<=limFront;i++){
		q.push({i,nums[i]-nums[i-1]});
	}
	for (int i=1;i<=limBack;i++){
		q.push({i,nums[n-i]-nums[n-i-1]});
	}
	while (!q.empty()&&k!=0){
		auto u=q.top();
		q.pop();
		if (k>=u.f*u.s){
			k-=u.f*u.s;
			ans-=u.s;
		} else {
			ans-=(k/u.f);
			k=0;
		}
	}
	cout<<ans<<endl;
}
