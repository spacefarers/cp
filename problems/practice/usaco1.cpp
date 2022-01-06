//
// Created by michaelyang on 2:43 AM Dec 31 2021.
// Problem: USACO 2019 US Open Contest, Gold
// Problem 1. Snakes

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
const int N=405;

pair<ll,ll> dp[N][N]; // min wasted for where you are now, how many changes
ll a[N],maxQ[N][N],pre[N];

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("snakes");
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		pre[i]=x;
		pre[i]+=pre[i-1];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			for (int l=i;l<=j;l++){
				maxQ[i][j]=max(maxQ[i][j],a[l]);
			}
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			dp[i][j]={1e12,1};
		}
	}
	for (int i=0;i<=k;i++){
		dp[1][i]={0,1};
	}
	for (int i=2;i<=n;i++){ // current position
		for (int j=1;j<i;j++){ // splitting path
			for (int l=0;l<=k;l++){ // number of changes
				if (l>=i-1) dp[i][l]={0,i};
				int lastSplit=dp[j][l].s;
				// no split
				ll ans;
				ll totSum=pre[i]-pre[lastSplit-1];
				ans=(i-lastSplit+1)*maxQ[lastSplit][i]-totSum+(dp[j][l].f-((j-lastSplit+1)*maxQ[lastSplit][j]-(pre[j]-pre[lastSplit-1])));
				if (ans<dp[i][l].f){
					dp[i][l]={ans,lastSplit};
				}
				// split
				if (l>0){
					ans=dp[j][l-1].f;
					totSum=pre[i]-pre[j];
					ans+=(i-j)*maxQ[j+1][i]-totSum;
					if (ans<dp[i][l].f){
						dp[i][l]={ans,j+1};
					}
				}
			}
		}
	}
	cout<<dp[n][k].f<<endl;
}