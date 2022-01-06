#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define f first
#define s second
#define ll long long

pair<double,double> points[155];

double dists[155][155];
double max_dists[155];

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>points[i].f>>points[i].s;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			dists[i][j]=1e9;
		}
		dists[i][i]=0;
	}
	for (int i=0;i<n;i++){
		string a;
		cin>>a;
		for (int j=0;j<n;j++){
			if (a[j]=='1') {
				double x=points[j].f-points[i].f,y=points[j].s-points[i].s;
				dists[i][j]=sqrt(double(x*x+y*y));
			}
		}
	}
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				dists[i][j]=min(dists[i][j],dists[i][k]+dists[k][j]);
			}
		}
	}
	double all_max=0;
	for (int i=0;i<n;i++){
		double max_dist=0;
		for (int j=0;j<n;j++){
			if (dists[i][j]>=1e9) continue;
			max_dist=max(max_dist,dists[i][j]);
		}
		all_max=max(all_max,max_dist);
		max_dists[i]=max_dist;
	}
	double connect_max=1e9;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (dists[i][j]<1e9||i==j) continue;
			double x=points[j].f-points[i].f,y=points[j].s-points[i].s;
			connect_max=min(connect_max,max_dists[i]+max_dists[j]+sqrt(double(x*x+y*y)));
		}
	}
	double ans=max(connect_max,all_max);
	if (connect_max==1e9) ans=all_max;
	printf("%.6f",ans);
}