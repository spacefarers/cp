#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		int n, c;
		cin>>n>>c;
		cout<<"Case #"<<i<<": ";
		vector<int> nums(n);
		for (int j=0;j<n;j++){
			nums[j]=j+1;
		}
		c-=(n-1);
		int change=1;
		if (c<0||n*(n-1)/2<c) goto impossible;
		for (int j=n-2;j>=0;j--){
			if (change>c) change=c;
			reverse(nums.begin()+j, nums.begin()+j+change+1);
			c-=change++;
			if (c==0) break;
		}
		for (auto &j:nums){
			cout<<j<<" ";
		}
		goto cont;
		impossible:;
		cout<<"IMPOSSIBLE";
		cont:;
		cout<<endl;
	}
}