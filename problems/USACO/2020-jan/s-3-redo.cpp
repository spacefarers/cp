#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

int visited[100005], pos[100005];
vector<pair<int, int>> adjs[100005];
int n, m;

bool validate(int x){
	memset(visited, -1, sizeof visited);
	int count=1;
	for (int i=1;i<=n;++i){
		if (visited[i]==-1){
			queue<int> q;
			q.push(i);
			while (!q.empty()){
				int u=q.front();
				q.pop();
				visited[u]=count;
				for (auto &j:adjs[u]){
					if (j.second>=x&&visited[j.first]==-1) {
						visited[j.first]=count;
						q.push(j.first);
					}
				}
			}
			count++;
		}
		if (visited[i]!=visited[pos[i]]) return false;
	}
	return true;
}

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("wormsort");
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>pos[i];
	}
	for (int i=0;i<m;++i){
		int a, b, c;
		cin>>a>>b>>c;
		adjs[a].emplace_back(b, c);
		adjs[b].emplace_back(a, c);
	}
	int x=-1;
	if (!validate(1e9)) {
		for (int i=1e9;i>=1;i/=2){
			while (validate(x+i)) x+=i;
		}
	}
	cout<<x<<endl;
}