//
// Created by michaelyang on 3:03 PM Jan 03 2022.
// Problem: Josephus Problem I

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
const int N=2e5+5;

int nextI[N],lastI[N];

int main(){
	fastio
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		nextI[i]=(i+1)%n;
		lastI[i]=(i+n-1)%n;
	}
	int c=min(1,n-1);
	while (nextI[c]!=c){
		cout<<c+1<<" ";
		nextI[lastI[c]]=nextI[c];
		lastI[nextI[c]]=lastI[c];
		c=nextI[nextI[c]];
	}
	cout<<c+1<<endl;
}