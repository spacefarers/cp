#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long t,N;
	cin>>t>>N;
	long long res=ceil(double(N*100-t)/t);
	res+=res*t/100;
	res++;
	cout<<res<<endl;
}