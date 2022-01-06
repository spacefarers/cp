#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a, x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

//int orientation(pi p, pi q, pi r){
//	int val=(q.s-p.s)*(r.f-q.f)-(q.f-p.f)*(r.s-q.s);
//	if (val==0) return 0;
//	return (val>0)?1:2;
//}
//
//bool check_intersect(pi p1, pi p2, pi q1, pi q2){
//	int o1 = orientation(p1, q1, p2);
//	int o2 = orientation(p1, q1, q2);
//	int o3 = orientation(p2, q2, p1);
//	int o4 = orientation(p2, q2, q1);
//	if (o1!=o2&&o3!=o4) return true;
//
//}

double cross_product(pi a, pi b, pi c){ // vector cross product
	return (b.f-a.f)*(c.s-a.s)-(c.f-a.f)*(b.s-a.s);
}

bool check_intersect(pi p1, pi p2, pi q1, pi q2){
	// Check if the two boxes collide
	if (min(p1.f, p2.f)>max(q1.f, q2.f)||min(q1.f, q2.f)>max(p1.f, p2.f)||min(p1.s, p2.s)>max(q1.s, q2.s)||
	    min(q1.s, q2.s)>max(p1.s, p2.s))
		return false;
	// Check the direction of the vectors, vector cross product
	if (cross_product(p1, q1, p2)*cross_product(p1, q2, p2)>0||
	    cross_product(q1, p1, q2)*cross_product(q1, p2, q2)>0)
		return false;
	return true;
}
int n;
pair<pl, pl> lines[100005];
vector<pair<pl, int>> points;
set<pair<ll, int>> active_list;

void final_processing(int i, int j){
	if (i>j) swap(i, j);
	bool ok=false;
	for (int k=j+1;k<n;k++){
		if (check_intersect(lines[i].f, lines[i].s, lines[k].f, lines[k].s)) {
			ok=true;
			break;
		}
	}
	if (!ok) {
		ok=true;
		for (int k=i+1;k<n;k++){
			if (k==j) continue;
			if (check_intersect(lines[j].f, lines[j].s, lines[k].f, lines[k].s)) {
				ok=false;
				break;
			}
		}
	}
	if (ok) cout<<i+1<<endl;
	else cout<<j+1<<endl;
	exit(0);
}

int main(){
	setIO("cowjump");
	cin>>n;
	for (int i=0;i<n;i++){
		ll a, b, c, d;
		cin>>a>>b>>c>>d;
		lines[i]={{a, b}, {c, d}};
		points.pb({{a, b}, i});
		points.pb({{c, d}, i});
	}
	sort(all(points));
////    O(n^2) approach
//	for (int i=0;i<n;i++){
//		for (int j=i+1;j<n;j++){
//			if (check_intersect(lines[i].f, lines[i].s, lines[j].f, lines[j].s)){
//				final_processing(i, j);
//			}
//		}
//	}
	// O(nlog(n)) Approach
	for (auto &i:points){
		auto it=active_list.find({lines[i.s].f.s, i.s});
		if (it==active_list.end()) {
			// inserting
			it=active_list.lower_bound({i.f.s, -0x7fffffff});
			if (it!=active_list.end()) {
				if (check_intersect(lines[(*it).s].f, lines[(*it).s].s, lines[i.s].f, lines[i.s].s))
					final_processing(i.s, (*it).s);
			}
			if (it!=active_list.begin()) {
				--it;
				if (check_intersect(lines[(*it).s].f, lines[(*it).s].s, lines[i.s].f, lines[i.s].s))
					final_processing((*it).s, i.s);
			}
			active_list.insert({lines[i.s].f.s, i.s});
		} else {
			// removing
			auto left=it, right=it;
			right++;
			if (right!=active_list.end()&&left!=active_list.begin()){
				--left;
				if (check_intersect(lines[(*right).s].f, lines[(*right).s].s, lines[(*left).s].f, lines[(*left).s].s)) final_processing(min((*left).s, (*right).s), max((*left).s, (*right).s));
			}
			active_list.erase(it);
		}
	}
	return 0;
}