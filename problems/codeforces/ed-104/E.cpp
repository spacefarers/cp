#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ll long long

ll cost[4][150005];
set<ll> non_compat[150005];

int main(){
	int n1, n2, n3, n4;
	cin>>n1>>n2>>n3>>n4;
	multiset<pair<ll, ll>> course1;
	for (int i=0;i<n1;i++){
		cin>>cost[0][i];
		course1.insert({cost[0][i], i});
	}
	for (int i=0;i<n2;i++){
		cin>>cost[1][i];
	}
	for (int i=0;i<n3;i++){
		cin>>cost[2][i];
	}
	for (int i=0;i<n4;i++){
		cin>>cost[3][i];
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		ll a, b;
		cin>>a>>b;
		a--;b--;
		non_compat[b].insert(a);
	}
	for (int i=0;i<n2;i++){
		auto it=course1.begin();
		while (it!=course1.end()&&non_compat[i].find((*it).second)!=non_compat[i].end()) it++;
		if (it==course1.end()) cost[1][i]+=1e12;
		else cost[1][i]+=(*it).first;
	}
	course1.clear();
	for (int i=0;i<n2;i++) course1.insert({cost[1][i], i});
	for (auto &i:non_compat) i.clear();
	cin>>m;
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		a--;b--;
		non_compat[b].insert(a);
	}
	for (int i=0;i<n3;i++){
		auto it=course1.begin();
		while (it!=course1.end()&&non_compat[i].find((*it).second)!=non_compat[i].end()) it++;
		if (it==course1.end()) cost[2][i]+=1e12;
		else cost[2][i]+=(*it).first;
	}
	course1.clear();
	for (int i=0;i<n3;i++) course1.insert({cost[2][i], i});
	for (auto &i:non_compat) i.clear();
	cin>>m;
	for (int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		a--;b--;
		non_compat[b].insert(a);
	}
	for (int i=0;i<n4;i++){
		auto it=course1.begin();
		while (it!=course1.end()&&non_compat[i].find((*it).second)!=non_compat[i].end()) it++;
		if (it==course1.end()) cost[3][i]+=1e12;
		else cost[3][i]+=(*it).first;
	}
	long long ans=1e12;
	for (int i=0;i<n4;i++){
		ans=min(ans, cost[3][i]);
	}
	if (ans>=(ll)1e12) ans=-1;
	cout<<ans<<endl;
}