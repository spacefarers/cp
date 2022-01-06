#include <iostream>

using namespace std;

int main(){
	int test_cases;
	cin>>test_cases;
	for (int test_case=0;test_case<test_cases;test_case++){
		int a;
		string b,c,d;
		cin>>a>>b;
		for (int i=0;i<a;i++){
			if (b[i]=='t'){
				d+='t';	
			} else {
				c+=b[i];
			}
		}
		cout<<c+d<<endl;
	}
}
