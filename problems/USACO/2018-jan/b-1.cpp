#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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
int x_1, x_2, x_3, x_4, y_1, y_2, y_3, y_4;

int main() {
    setIO("billboard");
    cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3>>x_4>>y_4;
    int x_box=max(min(x_2, x_4)-max(x_1, x_3), 0);
    int y_box=max(min(y_2, y_4)-max(y_1, y_3), 0);
    if ((x_box==x_2-x_1&&!(y_1<y_3&&y_4<y_2))||(y_box==y_2-y_1&&!(x_1<x_3&&x_4<x_2)))
        cout<<(x_2-x_1)*(y_2-y_1)-x_box*y_box;
    else
        cout<<(x_2-x_1)*(y_2-y_1);
    return 0;
}