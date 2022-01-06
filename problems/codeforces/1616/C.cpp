//
// Created by michaelyang on 11:41 AM Dec 29 2021.
// Problem: C. Representative Edges

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

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<double> nums(n);
		for (int i=0;i<n;i++){
			cin>>nums[i];
		}
		int mx=0;
		for (int i=0;i<n;i++){
			int x=nums[i];
			map<double,int> mp;
			for (int j=0;j<n;j++){
				if (i==j) continue;
				double diff=(nums[j]-x)/(j-i);
				mp[diff]++;
			}
			for (auto &j:mp){
				mx=max(mx,j.s);
			}
		}
		cout<<n-mx-1<<endl;
	}
}