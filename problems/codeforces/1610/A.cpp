//
// Created by spacefarers on 9:32 AM Nov 23 2021.
// Problem: A. Anti Light's Cell Guessing

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int a,b;
		cin>>a>>b;
		if (a==1&&b==1) cout<<0<<endl;
		else if (a==1||b==1) cout<<1<<endl;
		else cout<<2<<endl;
	}
}

