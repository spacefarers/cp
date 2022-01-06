//
// Created by spacefarers on 9:43 PM Nov 13 2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

bool present[26];

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		memset(present,false,sizeof present);
		string a,b;
		cin>>a>>b;
		for (char j:b){
			present[j-'a']=true;
		}
		int ans=0;
		for (char j:a){
			int x=0;
			while (true){
				if (present[(j-'a'+x)%26]) break;
				x++;
			}
			int y=0;
			while (true){
				if (present[(j-'a'-y+26)%26]) break;
				y++;
			}
			ans+=min(x,y);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}

