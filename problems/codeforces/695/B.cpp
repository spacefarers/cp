#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;

int nums[300005];
int n;

bool isIntimidate(int i){
	return (i>0&&i<n-1)&&((nums[i]>nums[i-1]&&nums[i]>nums[i+1])||(nums[i]<nums[i-1]&&nums[i]<nums[i+1]));
}

int cal_near(int i){
	int ans=0;
	if (isIntimidate(i-1)) ans++;
	if (isIntimidate(i)) ans++;
	if (isIntimidate(i+1)) ans++;
	return ans;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(nums, 0, sizeof nums);
		cin>>n;
		for (int i=0;i<n;i++) cin>>nums[i];
		int f_ans=0;
		for (int i=1;i<n-1;i++){
			if (isIntimidate(i)) f_ans++;
		}
		int max_num=0;
		for (int i=1;i<n-1;i++){
			int bp=nums[i];
			int before=cal_near(i);
			nums[i]=nums[i+1];
			max_num=max(max_num, before-cal_near(i));
			nums[i]=nums[i-1];
			max_num=max(max_num, before-cal_near(i));
			nums[i]=bp;
		}
		cout<<f_ans-max_num<<endl;
	}
}