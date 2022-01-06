#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N, K;
	cin>>N>>K;
	vector<int> ancestors;
	for (int i=0;i<N;i++){
		int a;
		cin>>a;
		ancestors.push_back(a);
	}
	ancestors.push_back(0);
	sort(ancestors.begin(), ancestors.end());
	int ans=ancestors.back()+12-ancestors.back()%12;
	vector<int> gaps;
	for (int i=0;i<N;i++){
		int a=ancestors[i]+(12-ancestors[i]%12)%12;
		int b;
		int u=i+1;
		b=ancestors[u]-ancestors[u]%12;
		if (b-a>0) gaps.push_back(b-a);
	}
	sort(gaps.begin(), gaps.end(), greater<>());
	for (int i=0;i<min(K-1, (int)gaps.size());i++){
		ans-=gaps[i];
	}
	cout<<ans<<endl;
}