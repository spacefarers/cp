#include <iostream>
#include <vector>
#include <array>
#include <set>

#define pi pair<int,int>
#define f first
#define s second

using namespace std;
#define PI 3.14159265
vector<vector<int>> permutations;
set<set<int>> permutations2;
vector<int> C;
set<int> C2;
int N;
bool used[50];
pi points[50];

void generate_permutations(){
	if (C.size()==N-3) {
		permutations.push_back(C);
		return;
	}
	for (int i=0;i<N;i++){
		if (used[i]) continue;
		C.push_back(i);
		used[i]=true;
		generate_permutations();
		used[i]=false;
		C.pop_back();
	}
}

double cross_product(pi a,pi b,pi c){
	return (b.f-a.f)*(c.s-a.s)-(c.f-a.f)*(b.s-a.s);
}

bool inTriangle(pi pt,pi a,pi b,pi c){
	double d1=cross_product(pt,a,b);
	double d2=cross_product(pt,b,c);
	double d3=cross_product(pt,c,a);
	bool has_neg=(d1<0)||(d2<0)||(d3<0);
	bool has_pos=(d1>0)||(d2>0)||(d3>0);
	return !(has_pos&&has_neg);
}

void generate_triange_permutations(){
	if (C2.size()==3) {
		permutations2.insert(C2);
		return;
	}
	for (int i=0;i<N;i++){
		if (used[i]) continue;
		C2.insert(i);
		used[i]=true;
		generate_triange_permutations();
		used[i]=false;
		C2.erase(i);
	}
}


bool checkDir(pi pt,pi a,pi b,pi c){
	// b as the central point
	double d1=cross_product(a,b,pt);
	double d2=cross_product(c,b,pt);
// if (!((a.f>b.f)^(c.f>b.f))&&((pt.f<b.f)^(a.f>b.f))) return false;
// if (!((a.s>b.s)^(c.s>b.s))&&((pt.s<b.s)^(a.s>b.s))) return false;
	if (cross_product(c,b,pt)*cross_product(c,b,a)>0) return false;
	return d1*d2<0;
}

int main(){
	cin>>N;
	for (int i=0;i<N;i++){
		cin>>points[i].f>>points[i].s;
	}
	generate_triange_permutations();
	int ans=0;
	for (auto &permutation2:permutations2){
		int c_ans=0;
		permutations.clear();
		auto it=permutation2.begin();
		array<pi,3> triangle{};
		for (int i=0;i<3;i++){
			triangle[i]=points[*it];
			used[*it]=true;
			it++;
		}
		generate_permutations();
		for (auto &permutation:permutations){
			bool ok=true;
			for (int i=0;i<N-3;i++){
				if (inTriangle(points[permutation[i]],triangle[0],triangle[1],triangle[2])) continue;
				for (int j=0;j<3;j++){
					if (checkDir(points[permutation[i]],triangle[(j+1)%3],triangle[j],triangle[(j+2)%3])) {
						triangle[j]=points[permutation[i]];
						goto cont;
					}
				}
				ok=false;
				cont:;
			}
			if (ok) c_ans++;
		}
		it=permutation2.begin();
		for (int i=0;i<3;i++){
			used[*it]=true;
			it++;
		}
		ans+=c_ans*3;
	}
	cout<<ans<<endl;
}