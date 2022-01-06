//
// Created by michaelyang on 11:33 PM Jan 01 2022.
// Problem: Road Construction

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

int father[N],groupSize[N],largestComp,numComp;

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a,int b){
	int c=find(a),d=find(b);
	if (c==d) return;
	numComp--;
	father[c]=d;
	groupSize[d]+=groupSize[c];
	largestComp=max(largestComp,groupSize[d]);
}

int main(){
	fastio
	int n,m;
	cin>>n>>m;
	numComp=n;
	for (int i=1;i<=n;i++){
		father[i]=i;
		groupSize[i]=1;
	}
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		unionn(a,b);
		cout<<numComp<<" "<<largestComp<<endl;
	}
}