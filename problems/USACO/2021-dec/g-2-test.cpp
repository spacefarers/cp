//
// Created by michaelyang on 7:00 PM Dec 26 2021.
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
#define pl pair<ll,ll>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=2e5+5;

int a[N],match[N];

int main(){
	fastio
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		match[x]=i;
	}
	for (int i=0;i<=n;i++){
		int mn=1e9,mx=0;
		string ans;
		for (int j=0;j<=n;j++){
			if (a[j]<mn&&a[j]>i){
				ans+="H";
				mn=a[j];
			} else if (a[j]>mx&&a[j]<=i){
				ans+="L";
				mx=a[j];
			}
		}
		int cans=0;
		for (int j=0;j<ans.size()-1;j++){
			if (ans.substr(j,2)=="HL"){
				cans++;
			}
		}
		cout<<cans<<endl;
	}
}