#include <iostream>

using namespace std;

int main(){
	int test_cases;
	cin>>test_cases;
	for (int i=0;i<test_cases;i++){
		int n;
		cin>>n;
		int inputs[n];
		for (int j=0;j<n;j++){
			cin>>inputs[j];
		}
		bool first_win=false;
		for (int j=0;j<n;j++){
			first_win = !first_win;
			if (inputs[j] != 1)
				break;
		}
		cout<<((first_win)?"First":"Second")<<endl;
	}
	return 0;
}
