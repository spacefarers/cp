#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int father[100005], counts[100005];
int n, k;
bool ans[100005];
vector<int> sums, new_arr, orig_arr;
vector<pair<int, int>> swaps;

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a);
	int d=find(b);
	father[c]=d;
	int u=sums[c];
	sums[d]+=u;
	sums[c]-=u;
}


void sim_round(){
	for (int i=0;i<k;i++){
//		if (find(new_arr[swaps[i].first])!=find(new_arr[swaps[i].second])){
//			counts[new_arr[swaps[i].first]]++;
//			counts[new_arr[swaps[i].second]]++;
//		}
		swap(new_arr[swaps[i].first], new_arr[swaps[i].second]);
		unionn(new_arr[swaps[i].first], new_arr[swaps[i].second]);
	}
}
bool vis[100005];
vector<int> path;
void dfs(int x, int dep){
	path.push_back(x);
	vis[x]=true;
	if (!vis[new_arr[x]]) {
		dfs(new_arr[x], dep+1);
	} else {
		int u=0;
		bool ok=false;
		for (auto &i:path){
			if (i==x) ok=true;
			counts[i]=dep+counts[x]-u;
			if (!ok) u++;
		}
	}
}

int main(){
	cin>>n>>k;
	for (int i=0;i<n;i++){
		father[i]=i;
		sums.push_back(1);
		orig_arr.push_back(i);
	}
	for (int i=0;i<k;i++){
		int a, b;
		cin>>a>>b;
		a--;b--;
		swaps.emplace_back(a, b);
	}
	new_arr=orig_arr;
	sim_round();
	for (int i=0;i<n;i++){
		if (new_arr[i]!=i) {
			if (!vis[i]) dfs(i, 0);
			cout<<counts[i]<<endl;
		} else {
			memset(ans, false, sizeof ans);
			ans[i]=true;
			int t=i;
			for (auto &j:swaps){
				if (j.first==t) {
					ans[j.second]=true;
					t=j.second;
				}
				else if (j.second==t) {
					ans[j.first]=true;
					t=j.first;
				}
			}
			int c_ans=0;
			for (int j=0;j<n;j++){
				if (ans[j]) c_ans++;
			}
			cout<<c_ans<<endl;
		}
	}
}