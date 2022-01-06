//
// Created by michaelyang on 11:03 AM Dec 29 2021.
// Problem: B. Mirror in the String

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=1e5+5;

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		int n;
		string x;
		cin>>n>>x;
		string best,c,bp,fin;
		for (int i=1;i<=n;i++){
			c+=x[i-1];
			bp=x[i-1]+bp;
			fin=c+bp;
			if (fin<best||best.empty()) best=fin;
		}
		cout<<best<<endl;
	}
}