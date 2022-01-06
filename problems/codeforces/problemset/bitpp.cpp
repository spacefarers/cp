#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin>>n;
	int count=0;
	for (int i=0;i<n;i++){
		string cmd;
		cin>>cmd;
		if (cmd == "X++"){
			count++;
		} else if (cmd == "X--"){
			count--;
		} else if (cmd == "++X"){
			count++;
		} else if (cmd == "--X"){
			count--;
		}
	}
	cout<<count<<endl;
}
