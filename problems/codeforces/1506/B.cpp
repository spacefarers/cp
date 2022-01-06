#include <iostream>
#include <vector>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n,k;
		cin>>n>>k;
		string a;
		cin>>a;
		vector<int> positions;
		for (int i=0;i<n;i++){
			if (a[i]=='*') positions.push_back(i);
		}
		int ans=1, last=positions.front();
		for (int i=1;i<positions.size()-1;i++){
			if (positions[i+1]-last>k){
				ans++;
				last=positions[i];
			}
		}
		if (positions.size()>1)
			ans++;
		cout<<ans<<endl;
	}
}