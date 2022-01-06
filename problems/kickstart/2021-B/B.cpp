#include <iostream>

using namespace std;

int nums[100005];

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int n;
		cin>>n;
		for (int j=0;j<n;j++){
			cin>>nums[j];
		}
		int last_fault=-1,left=0,d=nums[1]-nums[0],ans=2,last=nums[1];
		for (int j=2;j<n;j++){
			if (nums[j]-last!=d){
				if (last_fault<left) {
					last_fault=j;
					last+=d;
					goto cont;
				}
				if (last_fault+2>=n) break;
				left=last_fault-1;
				int d1=nums[last_fault]-nums[last];
				int d2=nums[last_fault+1]-nums[last_fault];
				int d3=nums[last_fault+2]-nums[last_fault+1];
				if (d1==d2||d1==d3) d=d1;
				else d=d2;
				j=left+1;
				last_fault-=2;
				last=nums[j];
				continue;
			}
			last=nums[j];
			cont:;
			int c_ans=j-left+1;
			if (last_fault<left&&c_ans<n) c_ans++;
			ans=max(ans,c_ans);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}