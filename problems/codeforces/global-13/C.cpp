#include <iostream>
#include <cstring>

using namespace std;

#define ll long long

int hits[5005];

int main(){
	int t;
	cin>>t;
	while (t--){
		memset(hits, 0, sizeof hits);
		int n;
		ll ans=0;
		cin>>n;
		for (int i=0;i<n;i++){
			int a;
			cin>>a;
			ans+=max(a-1-hits[i], 0);
			for (int j=i+2;j<min(a+i+1, n);j++){
				hits[j]++;
			}
			if (hits[i]>a-1){
				hits[i+1]+=hits[i]-a+1;
			}
		}
		cout<<ans<<endl;
	}
}