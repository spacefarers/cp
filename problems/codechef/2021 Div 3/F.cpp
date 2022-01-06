#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		int n, m;
		cin>>n>>m;
		map<int, vector<pair<bool, bool>>> mp;
		for (int i=0;i<n;i++){
			int a, b;
			cin>>a>>b;
			mp[a].emplace_back(true, true);
			mp[b].emplace_back(true, false);
		}
		for (int i=0;i<m;i++){
			int a, b;
			cin>>a>>b;
			mp[a].emplace_back(false, true);
			mp[b].emplace_back(false, false);
		}
		long long prev_time=0, active_A=0, active_B=0, ans=0;
		for (auto &i:mp){
			ans+=(i.first-prev_time)*active_A*active_B;
			int change_A=0, change_B=0;
			for (auto &j:i.second){
				if (j.first&&j.second) change_A++;
				else if (j.first&&!j.second) change_A--;
				else if (!j.first&&j.second) change_B++;
				else change_B--;
			}
			active_A+=change_A;
			active_B+=change_B;
			prev_time=i.first;
		}
		cout<<ans<<endl;
	}
}