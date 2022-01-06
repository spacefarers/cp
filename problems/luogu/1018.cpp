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

string multiply(const string& d, const string& e){
	int a[1005], b[1005], c[1005];
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	for (int i=0;i<d.size();i++) a[d.size()-i]=d[i]-'0';
	for (int i=0;i<e.size();i++) b[e.size()-i]=e[i]-'0';
	for (int i=1;i<=d.size();i++){
		int x=0;
		for (int j=1;j<=e.size();j++){
			c[i+j-1]=a[i]*b[j]+x+c[i+j-1];
			x=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
		c[i+e.size()]=x;
	}
	int c_len=(int)d.size()+(int)e.size();
	while (c[c_len]==0&&c_len>1) c_len--;
	string ans;
	for (int i=c_len;i>=1;i--){
		ans+=to_string(c[i]);
	}
	return ans;
}

bool precision_compare(const string& a, const string& b){
	if (a.size()==b.size()) return a>b;
	else return a.size()>b.size();
}

int n, k;
string a, f_ans;
vi list;
void solve(){
	if (list.size()==k){
		string ans=multiply(a.substr(0, list.front()), a.substr(list.back(), n-list.back()));
		for (int i=0;i<list.size()-1;i++){
			ans=multiply(ans, a.substr(list[i], list[i+1]-list[i]));
		}
		if (precision_compare(ans, f_ans)) f_ans=ans;
		return;
	}
	int u=1;
	if (!list.empty()) u=list.back()+1;
	for (int i=u;i<n;i++){
		list.push_back(i);
		solve();
		list.pop_back();
	}
}

int main() {
//    setIO("");
	cin>>n>>k>>a;
	solve();
	cout<<f_ans<<endl;
	return 0;
}

