//
// Created by spacefarers on 3:34 AM Nov 28 2021.
// Problem: Salary Queries

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;


int tree[400005],a[200005],num_count=0,c[200005],d[200005],inputs[400005];
char qType[200005];
map<int,int> mp;
int n;

void add(int k,int x){ // increment position k by x
	while (k<=num_count){
		tree[k]+=x;
		k+=k&-k; // this time we're going our way up
	}
}

int get_sum(int k){ // Sums form 0-k
	if (k<1) return 0;
	int s=0;
	while (k>=1){
		s+=tree[k];
		k-=k&-k; // keep getting smaller and decreasing in powers of 2
	}
	return s;
}

int main(){
	fastio
//	freopen("test.txt","r",stdin);
	int q;
	cin>>n>>q;
	vector<int> nums;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		nums.push_back(a[i]);
	}
	for (int i=0;i<q;i++){
		cin>>qType[i];
		cin>>c[i]>>d[i];
		nums.push_back(d[i]);
	}
	sort(nums.begin(),nums.end());
	for (auto&i:nums){
		mp[i]=++num_count;
	}
	for (int i=1;i<=n;i++) inputs[mp[a[i]]]++;
	for (int i=1;i<=num_count;i++) if (inputs[i]!=0) add(i,inputs[i]);
	for (int i=0;i<q;i++){
		if (qType[i]=='?'){
			auto it1=mp.upper_bound(d[i]);
			int bigNum;
			if (it1!=mp.begin())
				bigNum=get_sum(prev(it1)->s);
			else bigNum=0;
			auto it=mp.lower_bound(c[i]);
			int smallNum;
			if (it!=mp.begin())
				smallNum=get_sum(prev(it)->s);
			else smallNum=0;
			cout<<bigNum-smallNum<<endl;
		} else{
			add(mp[a[c[i]]],-1);
			add(mp[d[i]],1);
			a[c[i]]=d[i];
		}
	}
}

