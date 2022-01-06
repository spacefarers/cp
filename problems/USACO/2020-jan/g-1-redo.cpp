#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int earns[1005];
vector<int> paths[1005];

int dp[1005][1005];
int n, m, c;


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main(){
    setIO("time");
	cin>>n>>m>>c;
	for (int i=1;i<=n;i++){
		cin>>earns[i];
	}
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		paths[a].push_back(b);
	}
    memset(dp,-0x3f,sizeof dp);
	dp[1][0]=0;
    for (int i=0;i<1000;i++){
        for (int j=1;j<=n;j++){
            for (auto k:paths[j]){
                dp[k][i+1]=max(dp[k][i+1],dp[j][i]+c*i*i-c*(i+1)*(i+1)+earns[k]);
            }
        }
    }
	int ans=0;
    for (int i=0;i<1000;i++){
        ans=max(ans,dp[1][i]);
    }
    cout<<ans<<endl;
}