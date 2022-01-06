#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		long long n, u, v;
		cin>>n>>u>>v;
		long long last, last_2;
		long long ans=1e13;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			last_2=last;
			last=a;
			if (i>=1){
				if (last_2==last) ans=min(ans, min(u+v, v+v));
				else if (abs(last_2-last)==1) ans=min(ans, min(u, v));
				else ans=0;
			}
		}
		cout<<ans<<endl;
	}
}