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
    setIO("convention2");
	int n;
	cin>>n;
	vector<pair<int, pi>> cows;
	for (int i=0;i<n;i++){
		int a, b;
		cin>>a>>b;
		cows.pb({a, {b, i}});
	}
	sort(all(cows));
	priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> q;
	int t=0, ans=0;
	for (auto &i:cows){
		while (!q.empty()&&i.f>t){
			auto u=q.top();
			q.pop();
			if (t<u.s.s) t=u.s.s;
			ans=max(ans, t-u.s.s);
			t+=u.s.f;
		}
		q.push({i.s.s, {i.s.f, i.f}});
	}
	cout<<ans<<endl;
	return 0;
}