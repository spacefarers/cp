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
//    setIO("");
	int t;
	cin>>t;
	while (t--){
		int n, m;
		cin>>n;
		vi l1, l2;
		for (int i=0;i<n;++i){
			int a;
			cin>>a;
			l1.pb(a);
		}
		cin>>m;
		for (int i=0;i<m;++i){
			int a;
			cin>>a;
			l2.pb(a);
		}
		vi ssum_1(n), ssum_2(m);
		ssum_1[n-1]=l1[n-1];
		for (int i=n-2;i>=0;--i){
			ssum_1[i]=max(ssum_1[i+1]+l1[i], l1[i]);
		}
		ssum_2[m-1]=l2[m-1];
		for (int i=m-2;i>=0;--i){
			ssum_2[i]=max(ssum_2[i+1]+l2[i], l2[i]);
		}
		vi final;
		int l1_i=0, l2_i=0;
		for (int i=0;i<n+m;++i){
			if (l2_i!=m&&(l1_i==n||ssum_1[l1_i]<ssum_2[l2_i])){
				final.pb(l2[l2_i]);
				l2_i++;
			} else {
				final.pb(l1[l1_i]);
				l1_i++;
			}
		}
		int ans=0, c=0;
		trav(k, final){
			c+=k;
			ans=max(ans, c);
		}
		cout<<ans<<endl;
	}
	return 0;
}

