//
// Created by spacefarers on 5:30 PM Dec 22 2021.
// Problem: Problem 2. Exercise

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

using namespace std;

typedef __uint128_t L;
typedef long long ll;

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

struct FastMod{
	ll b,m;

	FastMod(ll b):b(b),m(ll((L(1)<<64)/b)){}

	ll reduce(ll a){
		ll q=(ll)((L(m)*a)>>64);
		ll r=a-q*b; // can be proven that 0 <= r < 2*b
		return r>=b?r-b:r;
	}
};

FastMod F(2);

ll gcd(ll a,ll b){
	if (b==0) return a;
	return gcd(b,a%b);
}

int MOD;
int n;


ll checkNums(const vector<int> &nums){
	vector<ll> travs;
	for (int i=0;i<n;i++){
		int c=nums[i];
		int moves=1;
		while (c!=i){
			moves++;
			c=nums[c];
		}
		travs.push_back(moves);
	}
	ll lcm=1;
	for (auto&i: travs){
		int g=gcd(lcm,i);
		lcm/=g;
		lcm*=i;
	}
	return lcm;
}

int main(){
	setIO("exercise");
	cin>>n>>MOD;
	F=FastMod(MOD);
	vector<int> nums;
	for (int i=0;i<n;i++){
		nums.push_back(i);
	}
	ll ans=1;
	do{
		ll res=checkNums(nums);
		ans*=res;
		ans=F.reduce(ans);
	} while (next_permutation(nums.begin(),nums.end()));
	cout<<ans<<endl;
}

