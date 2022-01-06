#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		string a;
		cin>>a;
		for (int i=0;i<a.size()+1;i++){
			if (i>0) {
				for (int j=0;j<=i;j++){
					if (a[j]==a[j+1]&&a[j]=='1') goto fail;
				}
			}
			if (i<a.size()) {
				for (int j=i;j<a.size()-1;j++){
					if (a[j]==a[j+1]&&a[j]=='0') goto fail;
				}
			}
			goto suc;
			fail:;
		}
		cout<<"NO"<<endl;
		continue;
		suc:;
		cout<<"YES"<<endl;
	}
}