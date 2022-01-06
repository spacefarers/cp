#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[100005];

int main(){
	int T;
	cin>>T;
	while (T--){
		memset(ans, 0, sizeof ans);
		int N;
		cin>>N;
		vector<pair<int, int>> patients;
		for (int i=0;i<N;i++){
			int a;
			cin>>a;
			patients.emplace_back(a, i);
		}
		sort(patients.begin(), patients.end(), [](pair<int, int> a, pair<int, int> b){
			if (a.first!=b.first) return a.first>b.first;
			return a.second<b.second;
		});
		for (int i=0;i<patients.size();i++){
			ans[patients[i].second]=i+1;
		}
		for (int i=0;i<N;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}