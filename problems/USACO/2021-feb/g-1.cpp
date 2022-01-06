#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define ll long long

int pre[1000005];

int main(){
	int n,mx=0;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		pre[a]++;
		mx=max(mx,a);
	}
	for (int i=1;i<=mx;i++){
		pre[i]+=pre[i-1];
	}
	auto get_prefix=[&](int x){
		return pre[min(mx, x)];
	};
	ll ans=0;
	for (int i=1;i<=mx;i++){
		vector<int> counts;
		for (int j=1;j*i<=mx;j++){
			counts.push_back(get_prefix(i*(j+1)-1)-get_prefix(i*j-1));
		}
		vector<int> odds;
		for (int j=0;j<counts.size();j++){
			if (counts[j]%2) odds.push_back(j);
		}
		if (odds==vector<int>{0}||(odds.size()==2&&odds.back()-odds.front()==1)){
			ans+=counts[odds.back()];
		}
	}
	cout<<ans<<endl;
}