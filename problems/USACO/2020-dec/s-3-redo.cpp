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

bool cmp(pair<pi, int> a, pair<pi, int> b){
	return a.f.s<b.f.s;
}

int blame[1005];
bool isStopped[1005];

int main() {
	int n;
	cin>>n;
	vector<pair<pi, int>> north, east;
	for (int i=0;i<n;i++){
		char a;
		int b, c;
		cin>>a>>b>>c;
		if (a=='E') east.pb({{b, c}, i});
		else north.pb({{b, c}, i});
	}
	sort(all(north));
	sort(all(east), cmp);
	for (auto &i:east){
		for (auto &j:north){
			if (isStopped[i.s]||isStopped[j.s]||i.f.f>j.f.f||i.f.s<j.f.s) continue;
			if (j.f.f-i.f.f>i.f.s-j.f.s){
				isStopped[i.s]=true;
				blame[j.s]+=blame[i.s]+1;
			} else if (j.f.f-i.f.f<i.f.s-j.f.s){
				isStopped[j.s]=true;
				blame[i.s]+=blame[j.s]+1;
			}
		}
	}
	for (int i=0;i<n;i++){
		cout<<blame[i]<<endl;
	}
	return 0;
}