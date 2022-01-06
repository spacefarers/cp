#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int,bool>> paths[200005];
int colored[200005];

bool ok=true;
int counts=0,dep=0;

void dfs(int x,bool color){
	if (colored[x]!=-1){
		if (colored[x]!=color) ok=false;
		return;
	}
	if (color) counts++;
	dep++;
	if (!ok) return;
	colored[x]=color;
	for (auto&i:paths[x]){
		dfs(i.first,color^(!i.second));
	}
}

int main(){
	int t;
	cin>>t;
	while (t--){
		ok=true;
		memset(colored,-1,sizeof colored);
		for (auto&i:paths){
			i.clear();
		}
		int n,m;
		cin>>n>>m;
		for (int i=0;i<m;i++){
			int a,b;
			string s;
			cin>>a>>b>>s;
			if (s!="crewmate"){
				paths[a].emplace_back(b,false);
				paths[b].emplace_back(a,false);
			} else{
				paths[a].emplace_back(b,true);
				paths[b].emplace_back(a,true);
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			counts=0,dep=0;
			if (colored[i]==-1) dfs(i,true);
			ans+=max(counts,dep-counts);
		}
		if (ok) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}