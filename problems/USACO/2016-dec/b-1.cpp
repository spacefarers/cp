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


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
    setIO("square");
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int m_l=max(max(max(x2-x1, abs(x2-x3)), x4-x3), abs(x4-x1));
    int m_w=max(max(max(y2-y1, abs(y2-y3)), y4-y3), abs(y4-y1));
    cout<<pow(max(m_l, m_w), 2)<<endl;
    return 0;
}