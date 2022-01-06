#include <iostream>
#include <vector>

using namespace std;

int stones[2000005];

int main(){
	int n;
	cin>>n;
	int max_a=0;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		stones[a]++;
		max_a=max(max_a, a);
	}
	for (int i=1;i<2000005;i++){
		stones[i]+=stones[i-1];
	}
	long long ans=0;
	for (int i=1;i<=max_a;i++){
		vector<pair<int,int>> odds;
		for (int j=1;i*j<=max_a;j++){
			int stones_num=stones[i*(j+1)-1]-stones[i*j-1];
			if (stones_num%2) odds.emplace_back(j,stones_num);
		}
		if ((odds.size()==1&&odds.front().first==1)||(odds.size()==2&&odds[1].first==odds[0].first+1)) ans+=odds.back().second;
	}
	cout<<ans<<endl;
}