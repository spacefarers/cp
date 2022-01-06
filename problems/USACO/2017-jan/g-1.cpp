#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int n;
ll tree[100005];

void add(int k, int x){
	while (k<=n){
		tree[k]+=x;
		k+=k&(-k);
	}
}

ll sum(int k){
	ll s=0;
	while (k>=1){
		s+=tree[k];
		k-=k&(-k);
	}
	return s;
}

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("bphoto");
	cin>>n;
	vector<int> nums1, nums_sorted;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		nums1.push_back(a);
		nums_sorted.push_back(a);
	}
	sort(nums_sorted.begin(),nums_sorted.end(), greater<>());
	map<int, int> mp;
	for (int i=1;i<=n;i++){
		mp[nums_sorted[i-1]]=i;
	}
	for (auto &i:nums1){
		i=mp[i];
	}
	int ans=0;
	for (int i=0;i<n;i++){
		ll prev_tall=sum(nums1[i]);
		ll after_tall=nums1[i]-prev_tall-1;
		if (min(prev_tall, after_tall)*2<max(prev_tall, after_tall)) ans++;
		add(nums1[i], 1);
	}
	cout<<ans<<endl;
}