#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
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
		string a;
		cin>>a;
		int c=0, d=0;
		bool ok=true;
		for (char i : a){
			if (-c>d) ok=false;
			if (i=='(') c++;
			else if (i==')') c--;
			else d++;
		}
		reverse(all(a));
		int e=0, g=0;
		trav(i, a){
			if (-e>g) ok=false;
			if (i==')') e++;
			else if (i=='(') e--;
			else g++;
		}
		c=abs(c);
		d-=c;
		if (d<0||d%2!=0||!ok) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

