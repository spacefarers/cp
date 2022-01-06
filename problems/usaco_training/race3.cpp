/*
ID: michael419
LANG: C++
TASK: race3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

vector<int> paths[55];
bool vis[55];
int i, aim;

bool dfs(int x){
	if (vis[x]) return false;
	vis[x]=true;
	if (x==aim) return true;
	return any_of(paths[x].begin(), paths[x].end(), [](int j){return dfs(j);});
}

int main(){
	setIO("race3");
	for (i=0;;i++){
		int x;
		cin>>x;
		if (x==-1) break;
		while (x!=-2){
			paths[i].push_back(x);
			cin>>x;
		}
	}
	vector<int> unavoidable, splitting_point;
	aim=i-1;
	for (int j=1;j<i-1;j++){
		vis[j]=true;
		if (!dfs(0)) unavoidable.push_back(j);
		memset(vis, false, sizeof vis);
	}
	cout<<unavoidable.size();
	for (auto &j:unavoidable){
		cout<<" "<<j;
		bool ok=true;
		for (auto &k:paths[j]){
			aim=j;
			if (dfs(k)){
				for (int l=0;l<j;l++){
					if (vis[l]) ok=false;
				}
			}
			memset(vis, false, sizeof vis);
		}
		if (ok) splitting_point.push_back(j);
	}
	cout<<endl<<splitting_point.size();
	for (auto &j:splitting_point){
		cout<<" "<<j;
	}
	cout<<endl;
}