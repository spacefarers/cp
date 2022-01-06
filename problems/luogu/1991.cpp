#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define f first
#define s second

int father[505];

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a), d=find(b);
	father[c]=d;
}

int main(){
	int s, p;
	cin>>s>>p;
	vector<pair<int, int>> points;
	for (int i=0;i<p;++i){
		father[i]=i;
		int a, b;
		cin>>a>>b;
		points.emplace_back(a, b);
	}
	vector<pair<double, pair<int, int>>> edges;
	for (int i=0;i<p;i++){
		for (int j=0;j<p;j++){
			if (i==j) continue;
			double x=points[i].f-points[j].f, y=points[i].s-points[j].s;
			edges.push_back({sqrt(x*x+y*y),{i, j}});
		}
	}
	sort(edges.begin(), edges.end());
	vector<double> mst;
	for (auto &i:edges){
		if (find(i.s.f)!=find(i.s.s)){
			unionn(i.s.f, i.s.s);
			mst.push_back(i.f);
		}
	}
	mst.push_back(0);
	sort(mst.begin(), mst.end());
	s--;
	while (s--&&mst.size()>1) mst.pop_back();
	printf("%.2f", mst.back());
}