#include <iostream>
#include <cstring>

using namespace std;

int has[26], c=0;

int main(){
	int t;
	cin>>t;
	while (t--){
		c=0;
		memset(has, 0, sizeof has);
		int n, k;
		cin>>n>>k;
		string a;
		cin>>a;
		for (char i : a){
			has[i-'a']++;
		}
		for (int ha : has){
			if (ha%k) goto cont1;
		}
		cout<<a;
		goto cont;
		cont1:;
		for (int ha : has){
			c+=(k-ha%k)%k;
		}
		for (int i=a.size();i>=1;i--){
			c-=(k-has[a[i-1]-'a']%k)%k;
			has[a[i-1]-'a']--;
			c+=(k-has[a[i-1]-'a']%k)%k;
			for (int j=a[i-1]-'a'+1;j<26;j++){
				int bp=c;
				c-=(k-has[j]%k)%k;
				has[j]++;
				c+=(k-has[j]%k)%k;
				if (c<=a.size()-i&&(a.size()-i-c)%k==0) {
					cout<<a.substr(0, i-1)<<char(j+'a');
					for (int l=0;l<(a.size()-i-c);l++){
						cout<<"a";
					}
					for (int l=0;l<26;l++){
						for (int m=0;m<(k-has[l]%k)%k;m++){
							cout<<char(l+'a');
						}
					}
					goto cont;
				}
				has[j]--;
				c=bp;
			}
		}
		cout<<-1;
		cont:;
		cout<<endl;
	}
}