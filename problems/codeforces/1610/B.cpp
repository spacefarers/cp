//
// Created by spacefarers on 9:41 AM Nov 23 2021.
// Problem: B. Kalindrome Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

#define f first
#define s second
#define ll long long

using namespace std;
vector<int> nums;
int n;

bool test(int x){
	int left=0,right=n-1;
	while (left<right){
		if (nums[left]==x){
			left++;
			continue;
		}
		if (nums[right]==x){
			right--;
			continue;
		}
		if (nums[left]!=nums[right]) return false;
		left++,right--;
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		nums.clear();
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			nums.push_back(a);
		}
		for (int i=0;i<n;i++){
			if (nums[i]!=nums[n-1-i]){
				bool a1=test(nums[i]);
				bool a2=test(nums[n-1-i]);
				if (a1||a2) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
				goto cont;
			}
		}
		cout<<"YES"<<endl;
		cont:;
	}
}

