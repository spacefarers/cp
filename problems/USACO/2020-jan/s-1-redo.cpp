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

int main() {
    setIO("berries");
	int n, k;
	cin>>n>>k;
	vi nums;
	for (int i=0;i<n;++i){
		int a;
		cin>>a;
		nums.pb(a);
	}
	int best_ans=0;
	sort(all(nums), greater<int>());
	for (int i=1;i<=nums[0];++i){
		priority_queue<int> q;
		trav(l, nums){
			int t=l;
			while (t>i){
				q.push(i);
				t-=i;
			}
			q.push(t);
		}
		int c=0;
		for (int j=0;j<k;++j){
			int u=q.top();
			q.pop();
			if (j>=k/2)
				c+=u;
		}
		best_ans=max(best_ans, c);
	}
	cout<<best_ans<<endl;
	return 0;
}

