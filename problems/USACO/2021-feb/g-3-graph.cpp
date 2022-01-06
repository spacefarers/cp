#include <iostream>

using namespace std;

int main(){
	for (int i=0;i<150;i++){
		for (int j=0;j<150;j++){
			bool ok=true;
			for (int k=0;k<10;k++){
				int x=(int)(i/pow(3, k))%3;
				int y=(int)(j/pow(3, k))%3;
				if (x%2!=y%2) ok=false;
			}
			if (ok) cout<<"\033[1;31m1\033[0m ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}