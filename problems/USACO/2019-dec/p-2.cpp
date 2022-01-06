//
// Created by spacefarers on 8:53 PM Dec 18 2021.
// Problem: Problem 2. Bessie's Snow Cow

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

struct node{
	node*par{};
	vector<node*> children;
	map<int,int> lazy;
	int colorfulness=0;
};

node *nodes[100005];

int main(){
	fastio
	int n,q;
	cin>>n>>q;
	nodes[1]=new node();
	for (int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		nodes[b]->par=nodes[a];
		nodes[a]->children.push_back(nodes[b]);
	}
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		if (a==1){
			int x,c;
			cin>>x>>c;
			
		}
	}
}

