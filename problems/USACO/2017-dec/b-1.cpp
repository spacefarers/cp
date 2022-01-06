/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int area(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int x_l=min(y4, y2)-max(y1, y3);
    int y_l=min(x2, x4)-max(x1, x3);
    if (x_l<0||y_l<0) return 0;
    return x_l*y_l;
}

int main() {
    setIO("billboard");
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
    int ar1=(x2-x1)*(y2-y1);
    int ar2=(x4-x3)*(y4-y3);
    ar1-=area(x1, y1, x2, y2, x5, y5, x6, y6);
    ar2-=area(x3, y3, x4, y4, x5, y5, x6, y6);
    int t_area=ar1+ar2;
    cout<<t_area<<endl;
    return 0;
}