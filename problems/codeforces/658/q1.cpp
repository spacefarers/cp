#include <iostream>

using namespace std;

int main(){
	int test_cases;
	cin>>test_cases;
	for (int i=0;i<test_cases;i++){
		int m, n;
		cin>>m>>n;
		int vec1[m];
		int vec2[n];
		for (int j=0;j<m;j++){
			cin>>vec1[j];
		}
		for (int j=0;j<n;j++){
			cin>>vec2[j];
		}
		bool ok=false;
		for (int j=0;j<m;j++){
			for (int a=0;a<n;a++){
				if (vec1[j] == vec2[a]){
					ok=true;
					cout<<"YES"<<endl;
					cout<<"1 "<<vec1[j]<<endl;
				}
				if (ok){
					break;
				}
			}
			if (ok){
				break;
			}
		}
		if (!ok)
			cout<<"NO"<<endl;
	}
	return 0;
}
