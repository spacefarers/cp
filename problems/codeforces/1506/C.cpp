#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		string a, b;
		cin>>a>>b;
		int ans=0;
		for (int i=0;i<a.size();i++){
			for (int j=0;j<b.size();j++){
				int c_ans=0;
				int e=i, f=j;
				while (e<a.size()&&f<b.size()&&a[e]==b[f]){
					c_ans++;
					e++,f++;
				}
				ans=max(ans, c_ans);
			}
		}
		cout<<a.size()+b.size()-2*ans<<endl;
	}
}