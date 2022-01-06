//
// Created by spacefarers on 5:04 PM Nov 25 2021.
// Problem: E. Nearest Opposite Parity

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

int a[200005],ans[200005];
queue<int> q,q1;
int n;
vector<int> paths[200005];

void check(int i,int j){
	if (i<0||j<0||i>=n||j>=n) return;
	if (a[i]%2==a[j]%2){
		if (ans[i]+1<ans[j]){
			ans[j]=ans[i]+1;
			q1.push(j);
		}
	}
}

int main(){
	fastio
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (i-a[i]>=0)
			paths[i-a[i]].push_back(i);
		if (i+a[i]<n)
			paths[i+a[i]].push_back(i);
	}
	memset(ans,0x3f,sizeof ans);
	for (int i=0;i<n;i++){
		if (i+a[i]<n&&a[i]%2!=a[i+a[i]]%2){
			q.push(i);
			ans[i]=1;
		}
		if (i-a[i]>=0&&a[i]%2!=a[i-a[i]]%2){
			q.push(i);
			ans[i]=1;
		}
	}
//	int t=2;
	while (true){
		while (!q.empty()){
			auto i=q.front();
			q.pop();
			for (auto&j:paths[i]){
				check(i,j);
			}
		}
		if (q1.empty()) break;
		swap(q,q1);
		while (!q1.empty()) q1.pop();
	}
	for (int i=0;i<n;i++){
		if (ans[i]>1e6) ans[i]=-1;
		cout<<ans[i]<<" ";
	}
}

