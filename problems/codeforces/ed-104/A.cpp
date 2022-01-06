#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<int> heroes;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			heroes.push_back(a);
		}
		sort(heroes.begin(), heroes.end());
		int val=heroes.front();
		int ans=0;
		for (auto &i:heroes){
			if (i>val) ans++;
		}
		cout<<ans<<endl;
	}
}