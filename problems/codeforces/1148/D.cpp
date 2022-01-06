//
// Created by spacefarers on 4:32 PM Nov 22 2021.
// Problem: D. Dirty Deeds Done Dirt Cheap

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

#define f first
#define s second
#define ll long long

using namespace std;

vector<pair<pair<int,int>,int>> upwards,downwards;

int main(){
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		if (a>b) downwards.push_back({{a,b},i+1});
		else upwards.push_back({{a,b},i+1});
	}
	sort(upwards.begin(),upwards.end(),greater<>());
	sort(downwards.begin(),downwards.end());
	if (upwards.size()<downwards.size()) swap(upwards,downwards);
	cout<<upwards.size()<<endl;
	for (auto&i:upwards){
		cout<<i.s<<" ";
	}
}

