#include <iostream>

using namespace std;

#define ll long long

int main(){
	int t;
	cin>>t;
	while (t--){
		ll n, m, x;
		cin>>n>>m>>x;
		x--;
		ll hori=x/n, vert=x%n;
		cout<<vert*m+hori+1<<endl;
	}
}