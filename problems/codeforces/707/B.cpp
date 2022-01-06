#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int creamed[200005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(creamed, 0, sizeof creamed);
		int n;
		cin>>n;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			a--;
			a=min(a, i);
			creamed[i-a]++;
			creamed[i+1]--;
		}
		int c=0;
		for (int i=0;i<n;i++){
			c+=creamed[i];
			cout<<((c>0)?1:0)<<" ";
		}
		cout<<endl;
	}
}