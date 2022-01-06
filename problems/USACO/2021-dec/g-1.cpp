//
// Created by michaelyang on 6:31 PM Dec 27 2021.
// Problem: Problem 1. Paired Up

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define pl pair<ll,ll>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=1e5+5;

pair<int,int> dp[N];

int main(){
	fastio
	int t,n,k;
	cin>>t>>n>>k;
	vector<vector<pair<int,int>>> chains;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if (!chains.empty()&&a-chains.back().back().f<=k) chains.back().push_back({a,b});
		else chains.push_back({{a,b}});
	}
	ll ans=0;
	if (t==1){
		for (auto &i:chains){
			if (i.size()%2){
				int mn=1e9;
				for (int j=0;j<i.size();j++){
					if (j==0||j==i.size()-1||j%2==0||i[j+1].f-i[j-1].f<=k)
						mn=min(mn,i[j].s);
				}
				ans+=mn;
			}
		}
	} else {
		for (auto &j:chains){
			n=j.size();
			dp[n]={0,-1e9};
			for (int i=n-1;i>=0;i--){
				dp[i]=dp[i+1];
				int nextK=upper_bound(j.begin(),j.end(),make_pair(j[i].f+k,(int)1e9))-j.begin();
				if (i==0||i==n-1||j[i+1].f-j[i-1].f<=k||(n-i)%2==0){
					dp[i].f=max(dp[i].f,dp[nextK].s+j[i].s);
				}
				if (i==0||i==n-1||j[i+1].f-j[i-1].f<=k||(n-i)%2){
					dp[i].s=max(dp[i].s,dp[nextK].f+j[i].s);
				}
			}
			if (n%2) ans+=dp[0].s;
			else ans+=dp[0].f;
			for (int i=0;i<=n;i++){
				dp[i]={0,0};
			}
		}
	}
	cout<<ans<<endl;
}