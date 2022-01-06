#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int z=1;
		for (int i=1e5;i>=1;i/=2){
			bool change=i%2;
			if (change) i++;
			while ((pow(z+i, 2)+1)/2<=n) z+=i;
			if (change) i--;
		}
		cout<<max((z-1)/2, 0)<<endl;
	}
}