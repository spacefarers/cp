#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		int M, H;
		cin>>M>>H;
		int val=M/H/H;
		if (val<=18) cout<<1<<endl;
		else if (val<=24) cout<<2<<endl;
		else if (val<=29) cout<<3<<endl;
		else cout<<4<<endl;
	}
}