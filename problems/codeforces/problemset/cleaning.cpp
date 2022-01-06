#include <iostream>
#include <vector>

using namespace std;

int front[100005], back[100005];

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		memset(front, -1, sizeof front);
		memset(back, -1, sizeof back);
		vector<int> nums, nums1;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			nums.push_back(a);
		}
		if (nums[0]<nums[1]){
			swap(nums[0], nums[1]);
			bool ok=true;
			for (int i=0;i<n-1;i++){
				nums[i+1]-=nums[i];
				if (nums[i+1]<0) {
					ok=false;
					break;
				}
			}
			if (ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			continue;
		}
		nums1=nums;
		for (int i=0;i<n;i++){
			if (nums[i]>nums[i+2]){

			}
		}
	}
}