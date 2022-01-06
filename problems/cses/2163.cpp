//
// Created by michaelyang on 3:16 PM Jan 03 2022.
// Problem: Josephus Problem II
#include<bits/stdc++.h>


#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=2e5+5;



int main(){
	fastio
	ordered_set nums;
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		nums.insert(i);
	}
	int c=k%n;
	while (n!=0){
		auto num=nums.find_by_order(c);
		cout<<*num<<" ";
		nums.erase(num);
		c+=k;
		n--;
		if (n!=0) c%=n;
	}
//	cout<<c-1<<endl;
}