#include <iostream>
#include <map>

using namespace std;

int nums[100005], track[100005];
map<int, int> in_list;
map<int, int, greater<>> mp;

int main(){
	int n, k;
	cin>>n>>k;
	k++;
	int last=0, c_item=-1;
	for (int i=0;i<n;i++){
		cin>>nums[i];
		if (nums[i]!=c_item){
			for (int j=last;j<i;j++){
				track[j]=i;
			}
			last=i,c_item=nums[i];
		}
	}
	for (int i=last;i<n;i++){
		track[i]=n;
	}
	int right=0,left=0,segs=0,ans=0;
	while (right<n){
		int next_pos=track[right];
		mp[nums[right]]+=next_pos-right;
		ans=max(ans, mp[nums[right]]);
		if (in_list[nums[right]]==0){
			segs++;
		}
		in_list[nums[right]]++;
		right=next_pos;
		while (segs>k){
			int next_left=track[left];
			mp[nums[left]]-=next_left-left;
			in_list[nums[left]]--;
			if (in_list[nums[left]]==0) segs--;
			left=next_left;
		}
	}
	cout<<ans<<endl;
}