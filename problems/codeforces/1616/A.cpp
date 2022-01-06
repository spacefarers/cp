//
// Created by michaelyang on 10:37 AM Dec 29 2021.
// Problem: A. Integer Diversity

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=1e5+5;

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int ans=0;
		map<int,int> mp;
		for (int i=0;i<n;i++){
			int x;
			cin>>x;
			if (x<0) x=-x;
			if (mp[x]==0||(mp[x]==1&&x!=0)) ans++;
			mp[x]++;
		}
		cout<<ans<<endl;
	}
}