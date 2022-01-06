//
// Created by spacefarers on 10:46 PM Nov 13 2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

ll prob[200005][2],MOD=1e9+7;

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		int n,q;
		cin>>n>>q;
		cin>>prob[1][0];
		prob[1][1]=1e6;
		for (int j=2;j<n+2;j++){
			int a,b,c;
			cin>>a>>b>>c;
			prob[j][0]=prob[a][0]*b+(prob[a][1]-prob[a][0])*c;
			prob[j][1]=prob[a][1]*(ll)1e6;
			prob[j][0]%=MOD;
			prob[j][1]%=MOD;
		}
		string ans;
		for (int j=0;j<q;j++){

		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}

