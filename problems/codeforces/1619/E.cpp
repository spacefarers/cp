//
// Created by michaelyang on 7:15 PM Jan 05 2022.
// Problem: E. MEX and Increments

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
const int N=2e5+5;

bool used[N];
multiset<int> unused;
ll ans,cnt[N];

ll fillBelow(int x){
	if (x<0) return 0;
	if (used[x]||ans==-1) return ans;
	auto it=unused.lower_bound(x);
	if (it!=unused.begin()){
		it=prev(it);
		ans+=(x-*it);
		unused.erase(it);
	} else {
		ans=-1;
	}
	return ans;
}

int main(){
	fastio
	int t;
	cin>>t;
	while (t--){
		memset(used,false,sizeof used);
		memset(cnt,0,sizeof cnt);
		unused.clear();
		ans=0;
		int n;
		cin>>n;
		for (int i=0;i<n;i++){
			int x;
			cin>>x;
			cnt[x]++;
			if (used[x]) unused.insert(x);
			else used[x]=true;
		}
		for (int i=0;i<=n;i++){
			ll val=fillBelow(i-1);
			if (ans==-1){
				cout<<ans<<" ";
				continue;
			}
			cout<<val+cnt[i]<<" ";
		}
		cout<<endl;
	}
}