//
// Created by michaelyang on 9:18 PM Dec 27 2021.
// Problem: Problem 1. Delegation

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

vector<int> G[N];

int main(){
	fastio
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
}