//
// Created by spacefarers on 12:15 AM Nov 29 2021.
// Problem: Edit Distance

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

int mem[5005][5005];

int editDistance(const string& a,const string& b,int m,int n){
	if (mem[m][n]!=-1) return mem[m][n];
	if (m==0) return n;
	if (n==0) return m;
	if (a[m-1]==b[n-1]) return editDistance(a,b,m-1,n-1);
	int ans=1+min(editDistance(a,b,m-1,n),min(editDistance(a,b,m,n-1),editDistance(a,b,m-1,n-1)));
	mem[m][n]=ans;
	return ans;
}

int main(){
	fastio
	memset(mem,-1,sizeof mem);
	string a,b;
	cin>>a>>b;
	cout<<editDistance(a,b,(int)a.size(),(int)b.size())<<endl;
}

