/*
ID: michael419
LANG: C++
TASK: fc
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

struct point {
	double x, y;
};

int orientation(point p, point q, point r){
	double val=(q.y-p.y)*(r.x-q.x)-(r.y-q.y)*(q.x-p.x);
	if (val==0) return 0;
	else if (val<0) return -1;
	else return 1;
}

double distSq(point p, point q){
	double x=p.x-q.x;
	double y=p.y-q.y;
	return x*x+y*y;
}

point nextToTop(stack<point> &S){
	point p=S.top();
	S.pop();
	point q=S.top();
	S.push(p);
	return q;
}

int main(){
	setIO("fc");
	int N;
	cin>>N;
	vector<point> points;
	int start=0;
	for (int i=0;i<N;i++){
		point p{};
		cin>>p.x>>p.y;
		points.push_back(p);
		if (p.y<points[start].y||(p.y==points[start].y&&p.x<points[start].x)) start=i;
	}
	swap(points.front(), points[start]);
	point p0=points.front();
	sort(points.begin()+1, points.end(), [p0](point a, point b){
		int o=orientation(p0, a, b);
		if (o==0) return distSq(p0, a)<=distSq(p0, b);
		return o==1;
	});
	int m=1;
	for (int i=1;i<N;i++){
		while (i<N-1&&orientation(p0, points[i], points[i+1])==0) i++;
		points[m++]=points[i];
	}
	if (m<3){
		cout<<"IMPOSSIBLE"<<endl;
		exit(0);
	}
	stack<point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	for (int i=3;i<m;i++){
		while (orientation(nextToTop(S), S.top(), points[i])!=1) S.pop();
		S.push(points[i]);
	}
	point last_p=S.top(), first_p=S.top();
	S.pop();
	double ans=0;
	while (!S.empty()){
		point p=S.top();
		S.pop();
		ans+=sqrt(distSq(last_p, p));
		last_p=p;
	}
	ans+=sqrt(distSq(last_p, first_p));
	printf("%.2f\n", ans);
}