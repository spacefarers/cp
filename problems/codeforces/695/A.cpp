#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		string ans;
		if (n==1) {
			ans="9";
			n=0;
		} else {
			ans="98";
			n-=2;
		}
		int temp=9;
		for (int i=0;i<n;i++){
			ans+=to_string(temp);
			temp++;
			if (temp==10) temp=0;
		}
		cout<<ans<<endl;
	}
}