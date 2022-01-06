#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		set<int> nums;
		int last_num=0;
		for (int j=0;j<n;j++){
			int a;
			cin>>a;
			nums.insert(a);
			last_num=max(last_num,a);
		}
//		nums.insert(k);
		int last=*nums.begin();
		vector<int> difs;
		for (auto &j:nums){
			difs.push_back(j-last-1);
			last=j;
		}
		sort(difs.begin(),difs.end(),greater<>());
		int ans=difs.front();
		vector<int> anss;
		anss.push_back((difs[0]+1)/2);
		if (difs.size()>1) anss.push_back((difs[1]+1)/2);
		anss.push_back(*nums.begin()-1);
		anss.push_back(k-last_num);
		sort(anss.begin(),anss.end(),greater<>());
		ans=max(ans,anss[0]+anss[1]);
		cout<<"Case #"<<i<<": ";
		printf("%.7f\n",double(ans)/k);
	}
}