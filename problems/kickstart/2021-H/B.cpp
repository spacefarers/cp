//
// Created by spacefarers on 10:12 PM Nov 13 2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

bool red[100005],yellow[100005],blue[100005];

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		memset(red,false,sizeof red);
		memset(yellow,false,sizeof yellow);
		memset(blue,false,sizeof blue);
		int x;
		string a;
		cin>>x>>a;
		for (int k=0;k<x;k++){
			auto j=a[k];
			if (j=='A'||j=='P'||j=='O'||j=='R') red[k]=true;
			if (j=='A'||j=='G'||j=='O'||j=='Y') yellow[k]=true;
			if (j=='A'||j=='P'||j=='G'||j=='B') blue[k]=true;
		}
		int ans=0;
		for (int j=0;j<x;j++){
			if (red[j]){
				ans++;
				while (red[++j]);
			}
		}
		for (int j=0;j<x;j++){
			if (yellow[j]){
				ans++;
				while (yellow[++j]);
			}
		}
		for (int j=0;j<x;j++){
			if (blue[j]){
				ans++;
				while (blue[++j]);
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}

