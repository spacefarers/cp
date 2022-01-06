//
// Created by michaelyang on 11:24 AM Dec 29 2021.
// Problem: 

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

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		int n;
		string x;
		cin>>n>>x;
		int ans=n-1;
		for (int i=0;i<n-1;i++){
			if (x[i]<x[i+1]){
				ans=i;
				goto cont;
			} else if (x[i]==x[i+1]){
				if (i==0){
					ans=i;
					goto cont;
				}
			}
		}
		cont:;
		string c=x.substr(0,ans+1);
		cout<<c;
		reverse(c.begin(),c.end());
		cout<<c<<endl;
	}
}