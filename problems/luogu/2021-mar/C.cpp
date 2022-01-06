#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long

bool states[500005];
vector<int> rev_graph[500005];
vector<int> graph[500005];
ll deg[500005],cost[500005],timeIn[500005],timeOut[500005],ans=-1;
vector<pair<ll,int>> dest_costs;

bool isAncestor(int a,int b){
	return timeIn[b]>=timeIn[a]&&timeIn[b]<=timeOut[a];
}

int n,t,a,b;

void search_ans(int x){
	ll c_cost=a*cost[x];
	bool ok=false;
	if (!dest_costs.empty()){
		c_cost+=dest_costs.front().first;
		if (ans==-1) ans=c_cost;
		else ans=min(ans,c_cost);
	}
	pair<ll,int> bp;
	for (auto it=dest_costs.begin();it!=dest_costs.end();it++){
		if ((*it).second==x) {
			bp=*it;
			dest_costs.erase(it);
			break;
		}
	}
	for (auto &i:graph[x]){
		int target=-1;
		ok=true;
		for (auto &j:graph[i]){
			if (!states[j]){
				if (target==-1) target=j;
				else ok=false;
			}
		}
		if (ok) search_ans(target);
	}
	dest_costs.push_back(bp);
	sort(dest_costs.begin(), dest_costs.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while (T--){
		dest_costs.clear();
		memset(states,false,sizeof states);
		memset(deg,0,sizeof deg);
		memset(cost,0,sizeof cost);
		ans=-1;
		cin>>n>>t>>a>>b;
		for (int i=0;i<n;i++){
			rev_graph[i].clear();
			graph[i].clear();
		}
		for (int i=1;i<n;i++){
			int x;
			cin>>x;
			x--;
			graph[x].push_back(i);
			rev_graph[i].push_back(x);
			deg[x]++;
		}
		for (int i=0;i<n;i++){
			cin>>cost[i];
		}
		stack<int> s;
		for (int i=0;i<n;i++){
			if (deg[i]==0) s.push(i);
			states[i]=false;
		}
		while (!s.empty()){
			auto u=s.top();
			s.pop();
			for (auto &i:rev_graph[u]){
				deg[i]--;
				states[i]=states[i]||(!states[u]);
				if (deg[i]==0) s.push(i);
			}
		}
		stack<int> stackOfChildren;
		int time=0;
		stackOfChildren.push(0);
		memset(timeIn,-1,sizeof timeIn);
		memset(timeOut,-1,sizeof timeOut);
		while (!stackOfChildren.empty()){
			int c=stackOfChildren.top();
			stackOfChildren.pop();
			if (timeIn[c]==-1) {
				timeIn[c]=time;
				time++;
				stackOfChildren.push(c);
				for (auto &i:graph[c]){
					stackOfChildren.push(i);
				}
			}
			if (timeIn[c]!=-1) {
				timeOut[c]=time-1;
			}
		}
		for (int i=0;i<n;i++){
			if (!states[i])
				dest_costs.emplace_back(cost[i]*b,i);
		}
		sort(dest_costs.begin(), dest_costs.end());
		if (t==0) {
			if (states[0]) ans=0;
			else search_ans(0);
		} else {
			if (!states[0]) ans=0;
			else {
				int target=-1;
				bool ok=true;
				for (auto &i:graph[0]){
					if (!states[i]) {
						if (target==-1) target=i;
						else ok=false;
					}
				}
				if (ok) search_ans(target);
			}
		}
		cout<<ans<<endl;
	}
}