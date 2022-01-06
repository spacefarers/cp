#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		string x;
		cin>>x;
		// if all As;
		for (auto &i:x){
			if (i!='a') goto cont1;
		}
		cout<<"NO"<<endl;
		continue;
		cont1:;
		cout<<"YES"<<endl;
		// if palindrome
		for (int i=0;i<x.size();i++){
			if (x[i]!=x[x.size()-i-1]) goto cont2;
		}
		cout<<"a"<<x<<endl;
		continue;
		cont2:;
		//if not
		cout<<x.substr(0,x.size()/2)<<"a"<<x.substr(x.size()/2,(x.size()+1)/2)<<endl;
	}
}