#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> nums;
map<int, int> avail;
vector<pair<int, int>> steps;
int n;

bool validate(){
	for (int i=0;i<n;i++){
		if (avail[nums[i]]==0) continue;
		avail[nums[i]]--;
		int t=i+1;
		while ((avail[nums[t]]==0)&&t<n) t++;
		if (t==n) return true;
		int match=nums[i]-nums[t];
		if (avail[match]==0||(match==nums[t]&&avail[match]<2)) return false;
		avail[match]--;
		steps.emplace_back(nums[t], match);
	}
	return true;
}

int main(){
	int t;
	cin>>t;
	vector<int> nums2;
	map<int, int> avail2;
	while (t--){
		avail.clear();
		nums.clear();
		cin>>n;
		n*=2;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			nums.push_back(a);
			avail[a]++;
		}
		sort(nums.begin(), nums.end(), greater<int>());
		nums2=nums;
		avail2=avail;
		bool ok=false;
		for (int i=1;i<n;i++){
			steps.clear();
			avail[nums[i]]--;
			nums.erase(nums.begin()+i);
			if (validate()) {
				cout<<"YES"<<endl;
				cout<<nums2[0]+nums2[i]<<endl;
				cout<<nums2[0]<<" "<<nums2[i]<<endl;
				for (auto &j:steps){
					cout<<j.first<<" "<<j.second<<endl;
				}
				ok=true;
				break;
			}
			nums=nums2;
			avail=avail2;
		}
		if (!ok) cout<<"NO"<<endl;
	}
}