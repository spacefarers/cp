#include <iostream>

using namespace std;

int main(){
	int n, q;
	string x;
	cin>>n>>x>>q;
	bool swaped=false;
	for (int i=0;i<q;i++){
		int a, b, c;
		cin>>a>>b>>c;
		b-=1,c-=1;
		if (a==1){
			if (swaped) b+=n,c+=n;
			b%=2*n;
			c%=2*n;
			swap(x[b],x[c]);
		} else {
			swaped=!swaped;
		}
	}
	if (swaped) cout<<x.substr(n,n)+x.substr(0,n);
	else cout<<x<<endl;
}