//
// Created by spacefarers on 3:09 PM Dec 03 2021.
// Problem: F1. Representative Sampling

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

int MOD=1e9+7;

int track[26][505];

int calc(vector<string> &a,int k){
	map<string,int> mp;
	int ans=0;
	for (auto&i:a){
		for (int j=1;j<=i.size();j++){
			ans+=mp[i.substr(0,j)]*j-mp[i.substr(0,j)]*(j-1);
			mp[i.substr(0,j)]++;
		}
	}
	for (auto&i: mp){
		track[i.f[0]-'a'][i.f.size()]=i.s;
	}
	
	return ans;
}

int main(){
	fastio
	int n,k;
	cin>>n>>k;
	vector<string> inputs;
	for (int i=0;i<n;i++){
		string x;
		cin>>x;
		inputs.push_back(x);
	}
	cout<<calc(inputs,k)<<endl;
}

