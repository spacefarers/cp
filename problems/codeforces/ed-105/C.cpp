#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mp;
#define ll long long

ll solve(const vector<ll> &box, const vector<ll> &sp){
	if (box.empty()||sp.empty()) return 0;
	mp.clear();
	ll cur=(ll)box.size()-1, c=0;
	for (ll i=(ll)sp.size()-1;i>=0;i--){
		while (cur>=0&&sp[i]<box[cur]) cur--;
		if (sp[i]==box[cur]) c++;
		mp[sp[i]]=c;
	}
	ll max_ans=0;
	for (int i=0;i<sp.size();i++){
		auto it=upper_bound(box.begin(), box.end(), sp[i]);
		ll dist=it-box.begin();
		auto it2=lower_bound(sp.begin(), sp.end(), sp[i]-dist+1);
		ll dist2=it2-sp.begin();
		dist2=i-dist2+1;
		ll more=mp[sp[i+1]];
		if (i==sp.size()-1) more=0;
		max_ans=max(max_ans, dist2+more);
	}
	return max_ans;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		vector<ll> box_pos, box_neg, sp_pos, sp_neg;
		int n, m;
		cin>>n>>m;
		for (int i=0;i<n;i++){
			ll a;
			cin>>a;
			if (a>0) box_pos.push_back(a);
			else box_neg.push_back(-a);
		}
		reverse(box_neg.begin(), box_neg.end());
		for (int i=0;i<m;i++){
			ll a;
			cin>>a;
			if (a>0) sp_pos.push_back(a);
			else sp_neg.push_back(-a);
		}
		reverse(sp_neg.begin(), sp_neg.end());
		cout<<solve(box_pos, sp_pos)+solve(box_neg, sp_neg)<<endl;
	}
}