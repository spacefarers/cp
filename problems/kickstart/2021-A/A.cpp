#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	for (int k=1;k<=t;k++){
		int a, b;
		cin>>a>>b;
		string c;
		cin>>c;
		c="1"+c;
		int goodness=0;
		for (int i=1;i<=a/2;i++){
			if (c[i]!=c[a-i+1]) goodness++;
		}
		cout<<"Case #"<<k<<": "<<abs(b-goodness)<<endl;
	}
}