#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int extreme=-1;

bool cmp(int a, int b){
	if (a==b) return false;
	cout<<a<<" "<<b<<" "<<extreme<<endl;
	cout<<flush;
	int ans;
	cin>>ans;
	return ans==a;
}

int main(){
	int t, n, q;
	cin>>t>>n>>q;
	while (t--){
		int ex1=1,ex2=2;
		vector<int> nums;
		for (int i=1;i<=n;i++) nums.push_back(i);
		for (int i=3;i<=n;i++){
			cout<<ex1<<" "<<ex2<<" "<<i<<endl;
			cout<<flush;
			int ans;
			cin>>ans;
			if (ans==ex1) ex1=i;
			else if (ans==ex2) ex2=i;
		}
		extreme=ex1;
		if (ex1>ex2) swap(ex1, ex2);
		nums.erase(nums.begin()+ex1-1);
		nums.erase(nums.begin()+ex2-2);
		sort(nums.begin(), nums.end(), cmp);
		cout<<ex1<<" ";
		for (auto &i:nums){
			cout<<i<<" ";
		}
		cout<<ex2<<endl<<flush;
		cin>>ex1;
	}
}