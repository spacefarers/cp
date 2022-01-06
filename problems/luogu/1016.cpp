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
	double d1, c, d2, p;
	int n;
	cin>>d1>>c>>d2>>p>>n;
	vector<pair<double, double>> stops(n);
	for (int i=0;i<n;i++){
		cin>>stops[i].f>>stops[i].s;
	}
	stops.emplace_back(d1, 0);
	sort(all(stops));
	double last=0;
	priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> q;
	q.push({p, c});
	double ans=0;
	for (auto &i:stops){
		bool ok=true;
		double left=i.f-last;
		while (ok){
			if (q.empty()) {
				cout<<"No Solution"<<endl;
				exit(0);
			}
			auto u=q.top();
			q.pop();
			if (left<=u.s*d2) {
				ans+=left/d2*u.f;
				q.push({u.f, u.s-(i.f-last)/d2});
				last=i.f;
				ok=false;
			} else {
				ans+=u.s*u.f;
				left-=u.s*d2;
			}
		}
		q.push({i.s, c});
	}
	printf("%.2f", ans);
	return 0;
}

