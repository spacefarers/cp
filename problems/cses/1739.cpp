//
// Created by michaelyang on 9:37 PM Jan 07 2022.
// Problem: Forest Queries II
// 2D BIT Implementatioon
// 2/10

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
const int N=1e3+5;

ll tree[N][N];
int n;

void add(int x,int y,int val){
	for (;x<=n;x+=(x&(-x))){
		for (int i=y;i<=n;i+=(i&(-i))){
			tree[x][i]+=val;
		}
	}
}

int get_sum(int x,int y){
	int ans=0;
	for (int i=x;i;i-=(i&(-i))){
		for (int j=y;j;j-=(j&(-j))){
			ans+=tree[i][j];
		}
	}
	return ans;
}

ll get_sum_box(int x1,int y1,int x2,int y2){
	return get_sum(x2,y2)-get_sum(x1-1,y2)-get_sum(x2,y1-1)+get_sum(x1-1,y1-1);
}

int main(){
	fastio
	int q;
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		string x;
		cin>>x;
		for (int j=1;j<=n;j++){
			if (x[j-1]=='*') add(i,j,1);
		}
	}
	for (int i=0;i<q;i++){
		int x;
		cin>>x;
		if (x==1){
			int a,b;
			cin>>a>>b;
			int p=get_sum_box(a,b,a,b);
			if (p==1) p=-1;
			else p=1;
			add(a,b,p);
		} else {
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<get_sum_box(x1,y1,x2,y2)<<endl;
		}
	}
}