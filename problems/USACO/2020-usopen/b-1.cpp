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
#include <algorithm>

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

int main() {
    setIO("socdist1");
    int n, lead_0=0, trail_0=0;
    cin>>n;
    string a;
    cin>>a;
    bool isone=false;
    while (a[0]=='0'){
        a=a.substr(1, a.size()-1);
        lead_0++;
    }
    while (a[a.size()-1]=='0'){
        a=a.substr(0, a.size()-1);
        trail_0++;
    }
    vi q;
    int last=0;
    for (int i=0;i<a.size();i++){
        if (a[i]=='1') isone=true;
        if (a[i]=='1'&&i!=last) {
            if (i!=1) {
                q.pb(i - last);
            }
            last=i;
        }
    }
    int c_min=0x7fffffff, c_min2=0x7fffffff, cmin_all=0, c_min3=0x7fffffff;
    if (!q.empty()){
        sort(all(q), greater<int>());
    //    all inside
        if (q.size()==1){
            c_min2=q[0]/2;
            c_min3=q[0]/3;
        } else {
            c_min=q[q.size()-1];
            pair<int, int> x, y;
            c_min2=min(c_min, q[0]/2);
            int b=q[0]-q[0]/2;
            if (q[0]/3>q[1]){
                y={b/2, b-b/2};
            } else {
                y={q[1]/2, q[1]-q[1]/2};
            }
            c_min3=min(c_min2, y.first);
        }
    }
//    one outside
    int zeros=max(trail_0, lead_0);
    if (!q.empty()){
        int c_min4=min(c_min2, zeros);
        cmin_all=max(c_min3, c_min4);
    }
//    Both outside
    int oneside=(isone)?zeros/2:zeros-1;
    int outside=max(min(min(c_min, trail_0), lead_0), oneside);
    cmin_all=max(cmin_all, outside);
    cout<<cmin_all<<endl;
    return 0;
}