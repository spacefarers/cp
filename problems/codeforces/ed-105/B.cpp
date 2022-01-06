#include <iostream>
#include <vector>

using namespace std;

int n;

bool invalid(int i, int j, int val){
	return i+j>val||(val==n&&(!i||!j))||(val==n-1&&(!i&&!j));
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		vector<int> sides(4); // U, R, D, L
		for (int i=0;i<4;i++){
			cin>>sides[i];
		}
		bool ok=false;
		for (int i=0;i<2;i++){
			for (int j=0;j<2;j++){
				for (int k=0;k<2;k++){
					for (int l=0;l<2;l++){
						if (invalid(i, j, sides[0])||invalid(j, k, sides[1])||invalid(k, l, sides[2])||invalid(l, i, sides[3])) continue;
						ok=true;
					}
				}
			}
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}