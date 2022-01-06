/*
ID: michael419
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int product_string(string a){
	int prod=1;
	for (int i; i<a.length();i++){
		prod *= (a[i]-64);
	}
	return prod;
}

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string a, b;
	fin >> a >> b;
	int prod1, prod2;
	prod1=product_string(a);
	prod2=product_string(b);
	fout << (prod1%47 == prod2%47?"GO":"STAY") << endl;
	return 0;
}
