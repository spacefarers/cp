//
// Created by spacefarers on 10:24 PM Nov 13 2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int x;
		string a;
		cin>>x>>a;
		while (true){
			bool changed=false;
			for (int j=0;j<10;j++){
				for (int k=0;k<a.size()-1;k++){
					if (a[k]-'0'==j&&a[k+1]-'0'==(j+1)%10){
						changed=true;
						a=a.substr(0,k)+char((j+2)%10+'0')+a.substr(k+2,a.size()-k-2);
					}
				}
			}
			if (!changed) break;
		}
		cout<<"Case #"<<i<<": "<<a<<endl;
	}
}

