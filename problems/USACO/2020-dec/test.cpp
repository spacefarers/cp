#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dp[25005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(dp, false, sizeof dp);
		int n, ans=0;
		cin>>n;
		vector<int> nums;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			nums.push_back(a);
		}
		sort(nums.begin(), nums.end(), greater<int>());
		int max_num=nums.front();
		vector<int> use;
		use.push_back(nums.back());
		nums.pop_back();
		dp[0]=true;
		for (int i=1;i<=max_num;i++){
			for (int j=0;j<use.size();j++){
				if (i-use[j]>=0&&dp[i-use[j]]) dp[i]=true;
			}
			if (i==nums.back()) {
				if (dp[i]) ans++;
				else {
					use.push_back(nums.back());
					dp[i]=true;
				}
				nums.pop_back();
			}
		}
		cout<<n-ans<<endl;
	}
}