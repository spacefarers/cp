#include <bits/stdc++.h>

using namespace std;

int space_avail[200005];

int main(){
	int t;
	cin>>t;
	while (t--){
		int n, W;
		cin>>n>>W;
		vector<int> nums(n);
		for (int i=0;i<n;i++){
			cin>>nums[i];
		}
		for (int i=0;i<2e5+5;i++){
			space_avail[i]=W;
		}
		sort(nums.begin(), nums.end(), greater<>());
		int max_reach=0;
		for (auto &i:nums){
			int x=-1;
			for (int j=1e5;j>=1;j/=2){
				while (space_avail[x+j]<i) x+=j;
			}
			x++;
			space_avail[x]-=i;
			max_reach=max(max_reach, x);
		}
		cout<<max_reach+1<<endl;
	}
}