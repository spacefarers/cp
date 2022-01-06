#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long

int c[100005], n;

void add(int k, int x){
	while (k<=n){
		c[k]+=x;
		k+=k&(-k);
	}
}

int get_sum(int k){
	int ans=0;
	while (k>0){
		ans+=c[k];
		k-=k&(-k);
	}
	return ans;
}

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("sleepy");
	cin>>n;
	vector<int> nums;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	}
	vector<int> not_working;
	int last=1e9;
	for (int i=(int)nums.size()-1;i>=0;i--){
		if (nums[i]>last){
			for (int j=i;j>=0;j--){
				not_working.push_back(nums[j]);
			}
			break;
		}
		add(nums[i],1);
		last=nums[i];
	}
	vector<int> ans;
	while (!not_working.empty()){
		int x=not_working.back();
		not_working.pop_back();
		auto pos=get_sum(x);
		add(x, 1);
		ans.push_back(not_working.size()+pos);
	}
	cout<<ans.size()<<endl;
	if (!ans.empty()){
		cout<<ans.front();
		for (int i=1;i<ans.size();i++){
			cout<<" "<<ans[i];
		}
		cout<<endl;
	}
}