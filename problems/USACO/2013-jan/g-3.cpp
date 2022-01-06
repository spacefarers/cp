//
// Created by spacefarers on 9:31 PM Nov 13 2021.
//
// todo: Finish this problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define f first
#define s second
#define ll long long

ll tree[800005][3],inputs[200005],lazy[800005];
int n;

void build_tree(int v=1, int tl=1, int tr=n){
	tree[v][0]=tr-tl+1;
	tree[v][1]=tr-tl+1;
	tree[v][2]=tr-tl+1;
	if (tl==tr){
		return;
	} else {
		int tm=(tl+tr)/2;
		build_tree(v*2, tl, tm);
		build_tree(v*2+1, tm+1, tr);
	}
}



int main(){
	int m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		char x;
		cin>>x;
		if (x=='A'){
			int a;
			cin>>a;
		} else {
			int a,b;
			cin>>a>>b;

		}
	}
}

