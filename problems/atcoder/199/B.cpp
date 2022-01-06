#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int max_num=0, min_num=1e9;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		max_num=max(max_num, a);
	}
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		min_num=min(min_num, a);
	}
	int ans=min_num-max_num+1;
	if (ans<0) ans=0;
	cout<<ans<<endl;
}