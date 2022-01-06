//
// Created by spacefarers on 5:02 PM Nov 21 2021.
// Problem: D. Game

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define f first
#define s second
#define ll long long

using namespace std;

int main(){
	int n;
	string x,bpx;
	cin>>n>>x;
	bpx=x;
	queue<int> matches;
	int st=0;
	int ans=1e9;
	for (int i=0;i<2;i++){
		int c_ans=0;
		for (int j=0;j<n;j++){
			if (x[j]==x[j+1]) matches.push(j);
		}
		while (!matches.empty()){
			auto u=matches.front();
			matches.pop();
			if (x[u]!=x[u+1]) continue;
			c_ans++;
			int cg=st;
			if (u%2) cg=1-cg;
			x[u]=char(cg+'0');
			x[u+1]=char(1-cg+'0');
			if (u-1>=0&&x[u]==x[u-1]){
				matches.push(u-1);
			}
			if (u+2<n&&x[u+1]==x[u+2]){
				matches.push(u+1);
			}
		}
		x=bpx;
		ans=min(ans,c_ans);
		st=1;
	}
	cout<<ans<<endl;
}