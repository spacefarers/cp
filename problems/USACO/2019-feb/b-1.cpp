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

int a[3];

int main() {
    setIO("herding");
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a+3);
    if (a[1]-a[0]==1&&a[2]-a[1]==1) cout<<0<<endl;
    else if (a[1]-a[0]==2||a[2]-a[1]==2) cout<<1<<endl;
    else cout<<2<<endl;
    cout<<max(a[2]-a[1], a[1]-a[0])-1<<endl;
    return 0;
}