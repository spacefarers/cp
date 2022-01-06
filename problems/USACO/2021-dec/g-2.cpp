//
// Created by michaelyang on 1:36 PM Dec 26 2021.
// Problem: Problem 2. HILO

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define pl pair<ll,ll>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;

const int MOD=1e9+7;
const int N=2e5+5;

int match[N],a[N],maxBlock[N];
bool state[N],counted[N];
set<int> LOs,ind;
vector<int> unblock[N];


int main(){
	fastio
	int n;
	cin>>n;
	ind.insert(0);
	ind.insert(n+1);
	state[n+1]=true;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		match[x]=i;
		state[i]=true; // set to HI
	}
	int cmin=1e9,cmax=0;
	set<int> cnums;
	cnums.insert(0);
	for (int i=1;i<=n;i++){
		if (a[i]<cmin){
			cmin=a[i];
			ind.insert(i);
		} else{
			maxBlock[i]=*prev(cnums.lower_bound(a[i]));
		}
		cnums.insert(a[i]);
	}
	for (int i=1;i<=n;i++){
		unblock[maxBlock[i]].push_back(i);
	}
	int ans=0;
	cout<<ans<<endl;
	for (int j=1;j<=n;j++){
		for (auto &k:unblock[j]){
			ind.insert(k);
		}
		int i=match[j];
		int prevNode=*prev(ind.lower_bound(i));
		state[i]=false; // set to LO
		ind.insert(i);
		LOs.insert(i);
		if (state[prevNode]){
			ans++;
			counted[i]=true;
		}
		auto it=LOs.upper_bound(i);
		while (it!=LOs.end()){
			if (counted[*it]) ans--;
			ind.erase(*it);
			LOs.erase(it++);
		}
		cout<<ans<<endl;
	}
}