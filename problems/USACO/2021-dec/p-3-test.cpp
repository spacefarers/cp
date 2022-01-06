//
// Created by spacefarers on 7:58 PM Dec 20 2021.
// Problem: 

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

int main(){
	fastio
	int n,x;
	cin>>n>>x;
	vector<int> nums;
	for (int i=1;i<=n;i++){
		nums.push_back(i);
	}
	int fans=0;
	set<string> ss;
	do {
		int lessTrack=0,moreTrack=n+1;
		char last='N';
		bool output=false;
		string ans;
		for (auto&i: nums){
			if (i<=x&&i>lessTrack){
				lessTrack=i;
				ans+="L";
				if (last=='H'){
					output=true;
					fans++;
				}
				last='L';
			} else if (i>x&&i<moreTrack){
				moreTrack=i;
				ans+="H";
				last='H';
			}
		}
		if (output){
//			for (auto&i: nums){
//				cout<<i<<" ";
//			}
//			cout<<"\n";
//			cout<<ans<<'\n';
			ss.insert(ans);
		}
	} while (next_permutation(nums.begin(),nums.end()));
//	cout<<fans<<'\n';
	for (auto&i: ss){
		cout<<i<<endl;
	}
}

