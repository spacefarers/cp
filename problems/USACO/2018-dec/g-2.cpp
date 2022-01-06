#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

using namespace std;
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

map<array<ll,5>,ll> mp;

int main(){
	setIO("cowpatibility");
	ll n;
	cin>>n;
	for (int i=0;i<n;i++){
		ll nums[5];
		for (ll &num:nums){
			cin>>num;
		}
		sort(nums,nums+5);
		for (int j=0;j<=1;j++){
			for (int k=0;k<=1;k++){
				for (int l=0;l<=1;l++){
					for (int m=0;m<=1;m++){
						for (int i1=0;i1<=1;i1++){
							int cur=0;
							array<ll,5> x{};
							if (j) x[cur++]=nums[0];
							if (k) x[cur++]=nums[1];
							if (l) x[cur++]=nums[2];
							if (m) x[cur++]=nums[3];
							if (i1) x[cur++]=nums[4];
							if (cur==0) continue;
							mp[x]++;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	for (auto &j:mp){
		ll combinations=j.second*(j.second-1)/2;
		ll zeros=0;
		for (int i=0;i<5;i++){
			if (j.first[i]==0) zeros++;
		}
		if (zeros%2) ans-=combinations;
		else ans+=combinations;
	}
	ans=n*(n-1)/2-ans;
	cout<<ans<<endl;
}