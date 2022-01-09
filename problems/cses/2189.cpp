//
// Created by michaelyang on 1:21 AM Jan 09 2022.
// Problem: Point Location Test

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
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pl;


const int MOD=1e9+7;
const int N=1e5+5;

double cross_product(pl a,pl b,pl c){
	return (b.f-a.f)*(c.s-a.s)-(c.f-a.f)*(b.s-a.s);
}

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		ll x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		pl p1,p2,p3;
		p1={x1,y1};
		p2={x2,y2};
		p3={x3,y3};
		if (cross_product(p1,p2,p3)<0) cout<<"RIGHT"<<endl;
		else if (cross_product(p1,p2,p3)>0) cout<<"LEFT"<<endl;
		else cout<<"TOUCH"<<endl;
	}
}