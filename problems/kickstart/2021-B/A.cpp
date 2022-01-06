#include <iostream>
#include <map>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int n;
		string x;
		cin>>n>>x;
		int left=0;
		cout<<"Case #"<<i<<": ";
		for (int j=0;j<n;j++){
			if (x[j]<=x[j-1]) left=j;
			cout<<j-left+1<<" ";
		}
		cout<<endl;
	}
}