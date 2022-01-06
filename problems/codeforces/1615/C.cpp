//
// Created by michaelyang on 11:57 PM Dec 28 2021.
// Problem: C. Menorah

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
		string a,b;
		cin>>n>>a>>b;
		int c0=0,c1=0,ans=-1,x0=0,x1=0;
		for (int i=0;i<n;i++){
			if (a[i]!=b[i]){
				// change by even
				if (a[i]=='0') c0++;
				else c1++;
			} else {
				// change by odd
				if (a[i]=='0') x0++;
				else x1++;
			}
		}
		if ((c1==c0||(c1==c0+1&&c1!=0))&&(c0+c1)%2==0) ans=c0+c1;
		if ((x0==x1||(x1==x0+1&&x1!=0))&&(x0+x1)%2!=0){
			if (ans==-1) ans=x0+x1;
			else ans=min(ans,x0+x1);
		}
		cout<<ans<<endl;
	}
}