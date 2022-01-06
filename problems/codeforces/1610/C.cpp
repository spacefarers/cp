//
// Created by spacefarers on 12:56 AM Nov 24 2021.
// Problem: C. Keshi Is Throwing a Party

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define f first
#define s second
#define ll long long

using namespace std;

vector<pair<int,int>> person;

bool check(int x){
	int c=0;
	for (auto&i:person){
		if (i.f>=c&&x-c-1<=i.s) c++;
	}
	return c>=x;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		person.clear();
		int n;
		cin>>n;
		for (int i=0;i<n;i++){
			int a,b;
			cin>>b>>a;
			person.emplace_back(a,b);
		}
		int z=0;
		for (int i=n;i>=1;i/=2){
			while (check(z+i)) z+=i;
		}
		cout<<z<<endl;
	}
}

