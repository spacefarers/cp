#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define f first
#define s second

double dist[5005];
int parent[505];

int main(){
	for (auto &i:dist){
		i=1e14;
	}
	int n;
	cin>>n;
	vector<pair<double, double>> points;
	for (int i=0;i<n;i++){
		double a, b;
		cin>>a>>b;
		points.emplace_back(a, b);
	}
	dist[0]=0;
	priority_queue<pair<double, int>> q;
	q.push({0, 0});
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f>dist[u.s]) continue;
		for (int i=0;i<n;i++){
			if (i==u.s||i==parent[u.s]) continue;
			double x=points[u.s].s-points[i].s,y=points[u.s].f-points[i].f;
			double dist_c=sqrt(x*x+y*y);
			if (dist[i]>dist_c){
				dist[i]=dist_c;
				parent[i]=u.s;
				q.push({dist[i], i});
			}
		}
	}
	double mst=0;
	for (int i=0;i<n;i++){
		mst+=dist[i];
	}
	printf("%.2f", mst);
}