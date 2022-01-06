#include <iostream>
#include <vector>

using namespace std;
#define f first
#define s second

int dp[1005][105];

int main(){
	int D, G;
	cin>>D>>G;
	vector<pair<int, pair<int,int>>> garbage(G);
	for (int i=0;i<G;i++){
		cin>>garbage[i].f>>garbage[i].s.f>>garbage[i].s.s;
	}
	sort(garbage.begin(), garbage.end());
	int max_time=garbage[G-1].f, cur=0;
//	for (int i=0;i<=max_time;i++){
//		if (garbage[cur].f==i){
//			for (int j=0;j<=D;j++){
//				dp[i+garbage[cur].s.f][j]=dp[i][j];
//				dp[i][j+garbage[cur].s.s]=dp[i][j];
//			}
//		}
//	}
	for (int i=0;i<G;i++){
		for (int j=D;j>=0;j--){
			if (dp[garbage[i].f][j]>=garbage[i].f)
			dp[garbage[i].f][j]=max(dp[garbage[i-1].f][j]
		}
	}
}