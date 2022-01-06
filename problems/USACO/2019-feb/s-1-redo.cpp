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
    setIO("herding");
	int n;
	cin>>n;
	vi nums(n);
	for (int i=0;i<n;i++) cin>>nums[i];
	sort(all(nums));
	int right=0, best=0;
	for (int i=0;i<n;i++){
		while (nums[i]+n>nums[right]&&right<n) right++;
		best=max(best, right-i);
	}
	if ((nums[1]-nums[0]>2&&nums[n-1]-nums[1]==n-2)||(nums[n-1]-nums[n-2]>2&&nums[n-2]-nums[0]==n-2)) best=n-2;
	cout<<n-best<<endl<<nums.back()-nums.front()-max(nums[1]-nums[0], nums[n-1]-nums[n-2]);
	return 0;
}

