// created by spacefarers at 2021.06.13

#include <iostream>

using namespace std;

long long poww(int x){
	long long ans=1;
	for (int i=0;i<x;i++){
		ans*=10;
	}
	return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--){
        long long n;
	cin>>n;
	if (n<2050||n%2050) {
		cout<<-1<<endl;
		continue;
	}
	int ans=0;
	for (int i=17;i>=0;i--){
		while (n>=2050*poww(i)){
			ans++;
			n-=2050*poww(i);
		}
	}
	cout<<ans<<endl;
    }
}
