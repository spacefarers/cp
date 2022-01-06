#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

pair<int, vi> ans;
vi seq;
int n, k;
int nums[10005];

int validate(){
	memset(nums, 0x3f, sizeof nums);
	int c=1;
	nums[0]=0;
	while (nums[c-1]<=n){
		for (auto &i:seq){
			if (c-i<0) continue;
			nums[c]=min(nums[c-i]+1, nums[c]);
		}
		c++;
	}
	return c-2;
}

void solve(){
	if (seq.size()==k){
		int t_ans=validate();
		if (t_ans>ans.f) ans={t_ans, seq};
		return;
	}
	int x=seq.back()+1;
	while (true){
		if (x>validate()+1) break;
		seq.pb(x);
		solve();
		seq.pop_back();
		x++;
	}
}

int main() {
//    setIO("");
	cin>>n>>k;
	seq.pb(1);
	solve();
	for (auto &i:ans.s){
		cout<<i<<" ";
	}
	cout<<endl<<"MAX="<<ans.f<<endl;
	return 0;
}

