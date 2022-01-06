#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

ll poww(int a, int b){
	ll ans=1;
	for (int i=0;i<b;i++){
		ans*=a;
	}
	return ans;
}

int main(){
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		ll a, b;
		cin>>a>>b;
		if (b<a){
			cout<<"NO"<<endl;
			continue;
		}
		int c=31;
		string ans, ans2;
		while (b<poww(2, c)) c--;
		while (c>=0){
			if (b>=poww(2, c)){
				b-=poww(2, c);
				ans+='1';
			} else ans+='0';
			c--;
		}
		c=31;
		while (a<poww(2, c)) c--;
		while (c>=0){
			if (a>=poww(2, c)){
				a-=poww(2, c);
				ans2+='1';
			} else ans2+='0';
			c--;
		}
		int carry=0;
		bool ok=true;
		reverse(ans.begin(), ans.end());
		reverse(ans2.begin(), ans2.end());
		int c0=0, c1=0;
		for (int j=0;j<ans.size();j++){
			if (ans[j]=='1') c1++;
			if (j<ans2.size()&&ans2[j]=='1') c0++;
			if (c0<c1){
				ok=false;
				break;
			}
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}