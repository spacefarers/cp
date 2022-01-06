// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(a, b);
	return distr(gen);
}

int main() {
	int n = rand(2, 10);
	cout<<n<<endl;
	vector<int> nums;
	for (int i=1;i<=n;i++){
		nums.push_back(i);
	}
	for (int i=0;i<n;i++){
		int x=rand(0,nums.size()-1);
		cout<<nums[x]<<" ";
		nums.erase(nums.begin()+x,nums.begin()+x+1);
	}
	cout<<endl;
}