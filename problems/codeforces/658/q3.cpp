#include <iostream>

using namespace std;

int bfs(){
	
}


string transform(string a, int prefix){
	string prefixed_part = a.substr(0, prefix);
	for (int i=0;i<prefix;i++)
		prefixed_part[i] = (prefixed_part[i] == "0")?"1":"0";
	for (int i=0;i<prefix/2;i++)
		swap(prefixed_part[i], prefixed_part[n - i - 1]);
	return a;
}

int main(){
	int test_cases;
	cin>>test_cases;
	for (int i=0;i<test_cases;i++){
		int n;
		cin>>n;
		string a, b;
		cin>>a>>b;
	}
	return 0;
}
