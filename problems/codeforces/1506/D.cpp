#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		map<int, int> mp;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			mp[a]++;
		}
		vector<int> times;
		times.reserve(mp.size());
		for (auto &i:mp){
			times.push_back(i.second);
		}
		sort(times.begin(), times.end(), greater<>());
		int sum_all=0;
		for (auto &i:times){
			sum_all+=i;
		}
		if (sum_all-times.front()<=times.front()){
			cout<<times.front()-sum_all+times.front()<<endl;
		} else {
			cout<<sum_all%2<<endl;
		}
	}
}