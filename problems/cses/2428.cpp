//
// Created by spacefarers on 11:46 PM Nov 28 2021.
// Problem: Subarray Distinct Values

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

map<int,int> mp;
int a[200005];

int main(){
	fastio
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ll right=-1,ans=0;
	for (int i=0;i<n;i++){
		if (i!=0){
			if (--mp[a[i-1]]==0){
				mp.erase(a[i-1]);
			}
		}
		while (mp.size()<=k&&right!=n){
			right++;
			if (right==n) break;
			mp[a[right]]++;
		}
		ans+=right-i;
	}
	cout<<ans<<endl;
}

