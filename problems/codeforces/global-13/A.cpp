#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, q;
	cin>>n>>q;
	int count=0;
	vector<int> nums;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		if (a==1) count++;
		nums.push_back(a);
	}
	for (int i=0;i<q;i++){
		int a, b;
		cin>>a>>b;
		if (a==1){
			if (nums[b-1]==0) count++;
			else count--;
			nums[b-1]=1-nums[b-1];
		} else {
			cout<<((count>=b)?1:0)<<endl;
		}
	}
}