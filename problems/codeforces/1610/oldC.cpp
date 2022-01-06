//
// Created by spacefarers on 10:59 AM Nov 23 2021.
// Problem: C. Keshi Is Throwing a Party

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

#define f first
#define s second
#define ll long long

using namespace std;

int prop[200005];
map<int,int> mp;

void update(int x,int p){
//	int i=0;
//	int i=mp.lower_bound(p)->s+1;
	int z=x;
	for (int j=x-0;j>=1;j/=2){
		if (z-j<0) continue;
		while (prop[z-j]==-1) z-=j;
	}
	for (int j=z;j>=0;j--){
		prop[j+1]=max(prop[j+1],min(prop[j]-1,p));
	}
//	mp[p]=z;
//	auto it=mp.lower_bound(p);
//	it--;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(prop,-1,sizeof prop);
		mp.clear();
		mp[1e9]=-1;
		mp[0]=1e9;
		int n;
		cin>>n;
		prop[0]=1e9;
		for (int i=0;i<n;i++){
			int a,b;
			cin>>b>>a;
			update(a,b);
		}
		int i;
		for (i=0;;i++){
			if (prop[i]<0){
				break;
			}
		}
		cout<<i-1<<endl;
	}
}

