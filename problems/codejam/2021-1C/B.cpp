#include <iostream>

using namespace std;

bool check(const string &x){
	for (int i=1;i<=x.size()/2;i++){
		long long a=stoll(x.substr(0,i));
		string f=x.substr(i,x.size()-i);
		while (!f.empty()){
			string y=to_string(++a);
			if (y.size()>f.size()) goto cont;
			string z=f.substr(0,y.size());
			if (z!=y) goto cont;
			f=f.substr(y.size(),f.size()-y.size());
		}
		return true;
		cont:;
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		long long a;
		cin>>a;
		while (!check(to_string(++a)));
		cout<<"Case #"<<i<<": "<<a<<endl;
	}
}