#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int tot[100005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(tot, 0, sizeof tot);
		int n, m;
		cin>>n>>m;
		vector<set<int>> days;
		for (int i=0;i<m;i++){
			int k;
			cin>>k;
			set<int> day;
			for (int j=0;j<k;j++){
				int x;
				cin>>x;
				x--;
				tot[x]++;
				day.insert(x);
			}
			days.push_back(day);
		}
		int num_over_half=0;
		for (int i=0;i<n;i++){
			if (tot[i]>(m+1)/2){
				num_over_half++;
			}
		}
		if (num_over_half==0){
			cout<<"YES"<<endl;
			for (auto &i:days){
				cout<<*i.begin()+1<<" ";
			}
			cout<<endl;
		} else {
			bool ok=false;
			for (int i=0;i<n;i++){
				if (tot[i]>(m+1)/2){
					int bp=tot[i];
					bp-=(m+1)/2;
					for (int j=0;j<m;j++){
						if (days[j].find(i)!=days[j].end()&&days[j].size()!=1){
							tot[i]--;
						}
					}
					if (tot[i]<=(m+1)/2) {
						cout<<"YES"<<endl;
						for (int j=0;j<m;j++){
							if (days[j].find(i)!=days[j].end()&&days[j].size()!=1&&bp){
								bp--;
								auto it=days[j].begin();
								if (*it==i) it++;
								cout<<*it+1<<" ";
							} else if (days[j].find(i)==days[j].end()) {
								cout<<*days[j].begin()+1<<" ";
							} else cout<<i+1<<" ";
						}
						cout<<endl;
						ok=true;
						break;
					}
				}
			}
			if (!ok) cout<<"NO"<<endl;
		}
	}
}