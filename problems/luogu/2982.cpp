#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> paths[100005];
int n;
int which_cow[100005], ans[100005], tree[100005];

int sum(int k){
	int s=0;
	while (k>0){
		s+=tree[k];
		k-=k&(-k);
	}
	return s;
}

void add(int k, int x){
	while (k<=n){
		tree[k]+=x;
		k+=k&(-k);
	}
}

void dfs(int x, int from){
	ans[which_cow[x]]=sum(which_cow[x]);
	add(which_cow[x], 1);
	for (auto &i:paths[x]){
		if (i==from) continue;
		dfs(i, x);
	}
	add(which_cow[x], -1);
}

int main(){
	cin>>n;
	for (int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		which_cow[a]=i;
	}
	dfs(1, -1);
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
}