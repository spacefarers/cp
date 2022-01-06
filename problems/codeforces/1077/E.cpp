//
// Created by spacefarers on 12:28 PM Nov 23 2021.
// Problem: E. Thematic Contests

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

#define f first
#define s second
#define ll long long

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	map<int,int> mp;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		mp[x]++;
	}
	vector<int> nums;
	nums.reserve(mp.size());
	for (auto&i:mp){
		nums.push_back(i.s);
	}
	sort(nums.begin(),nums.end());
	int ans=0;
	for (int i=1;i<=*prev(nums.end());i++){
		int c=i,ind=(int)nums.size()-1;
		int c_ans=0;
		while (true){
			c_ans+=c;
			if (c%2) break;
			c/=2;
			if (--ind<0||nums[ind]<c) break;
		}
		ans=max(ans,c_ans);
	}
	cout<<ans<<endl;
}

