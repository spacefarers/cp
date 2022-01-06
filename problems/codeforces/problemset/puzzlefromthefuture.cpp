#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int a;
		cin>>a;
		string c;
		cin>>c;
		string ans="1";
		bool last=true;
		for (int i=1;i<a;i++){
			if (c[i]==c[i-1]) last=!last;
			else if (last&&c[i-1]=='0'||!last&&c[i-1]=='1') {
				last=last;
			} else last=true;
			ans+=last?"1":"0";
		}
		cout<<ans<<endl;
	}
}