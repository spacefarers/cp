#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int father[100005], numbers[100005];
map<int, set<int>> mp;

int find(int x){
	if (x!=father[x]) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a);
	int d=find(b);
	father[c]=d;
	int change=numbers[c];
	numbers[d]+=change;
	numbers[c]-=change;
	mp[d].insert(mp[c].begin(), mp[c].end());
	mp[c].clear();
}

int main(){
	int n;
	cin>>n;
	set<pair<int, int>, greater<>> q;
	for (int i=1;i<=n;i++){
		numbers[i]=1;
		father[i]=i;
		q.insert({1, i});
	}
	for (int i=0;i<n-1;i++){
		int a, b;
		cin>>a>>b;
		mp[a].insert(b);
		mp[b].insert(a);
	}
	bool ok=true;
	while (q.size()>1){
		auto q1=q.begin();
		bool hit=false;
		while (!hit){
			for (auto &i:mp[(*q1).second]){
				if (find(i)==(*q1).second) continue;
				if (numbers[find(i)]<=(*q1).first&&numbers[find(i)]*2>=(*q1).first) {
					hit=true;
					q.erase(q.find({numbers[find(i)], find(i)}));
					unionn((*q1).second,find(i));
					q.erase(q1);
					q.insert({numbers[find(i)], find(i)});
					break;
				}
			}
			if (!hit) {
				q1++;
				if (q1==q.end()) {
					ok=false;
					break;
				}
			}
		}
		if (!ok) break;
	}
	if (ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}