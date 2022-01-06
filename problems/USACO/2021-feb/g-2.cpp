#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int deg[305];
set<int> paths[305];
bool done[305];
int N;
map<int, vector<int>> mp2;
vector<int> target, current;
set<int> key_pos;
int ans=0;

void solve(){
	bool changed=false;
	for (int i=1;i<=N;i++){
		if (deg[i]==0&&!done[i]) {
			changed=true;
			done[i]=true;
			ans++;
			bool clear=true;
			for (int j=0;j<mp2[i].size()-1;j++){
				for (int k=mp2[i][j];k<=mp2[i][j+1];k++){
					if (key_pos.find(j)!=key_pos.end()) clear=false;
				}
				if (!clear){
					ans++;
					current[mp2[i][j]]=i;
					current[mp2[i][j+1]]=i;
				}
				for (int k=mp2[i][j];k<=mp2[i][j+1];k++){
					current[j]=i;
				}
			}
			if (mp2[i].size()==1){
				current[mp2[i].front()]=i;
			}
			for (auto &j:mp2[i]){
				key_pos.insert(j);
			}
			for (auto &j:paths[i]){
				deg[j]--;
			}
		}
	}
	if (!changed){
		auto bp=current;
		vector<pair<int, int>> pending;
		for (int i=1;i<=N;i++){
			if (!done[i]) pending.emplace_back(deg[i], i);
		}
		sort(pending.begin(), pending.end());
		vector<int> items;
		int cur=0;
		while (pending[cur].first==pending.front().first){
			items.push_back(pending[cur++].second);
		}
		do {
			int bp2=deg[items.front()];
			deg[items.front()]=0;
			solve();
			current=bp;
			deg[items.front()]=bp2;
		} while (next_permutation(items.begin(), items.end()));
	}
}

int main(){
	cin>>N;
	for (int i=0;i<N;i++) current.push_back(0);
	memset(done, true, sizeof done);
	for (int i=0;i<N;i++){
		int a;
		cin>>a;
		target.push_back(a);
		mp2[a].push_back(i);
		done[a]=false;
	}
	for (int i=1;i<=N;i++){
		if (done[i]) continue;
		for (int j=0;j<mp2[i].size()-1;j++){
			for (int k=mp2[i][j];k<mp2[i][j+1];k++){
				if (paths[i].find(target[k])==paths[i].end()){
					paths[i].insert(target[k]);
					deg[target[k]]++;
				}
			}
		}
	}
	while (current!=target) solve();
	cout<<ans<<endl;
}