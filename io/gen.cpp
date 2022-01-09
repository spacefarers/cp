// generating a random sequence of distinct elements
#include "testlib.h"
#include <iostream>
#include <random>

using namespace std;

int rand(int a,int b){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(a,b);
	return distr(gen);
}

int main(){
	int n=rand(1,400);
	int k=rand(0,n-1);
//	cout<<1<<endl;
			cout<<n<<" "<<k<<endl;
//	string x;
	for (int i=0;i<n;i++){
//		x+=char('a'+rand(0,25));
		cout<<rand(1,1000000)<<" ";
	}
	cout<<endl;
//	cout<<x<<endl;
}