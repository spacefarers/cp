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

int main() {
    setIO("blist");
    int n;
    int cows[1005];
    memset(cows, 0, sizeof(cows));
    cin>>n;
    int max_s=0;
    for (int i=1;i<=n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        max_s=max(max_s, b);
        for (int j=a;j<=b;j++){
            cows[j]+=c;
        }
    }
    int ans=0;
    for (int i=1;i<=max_s;i++){
        ans=max(ans, cows[i]);
    }
    cout<<ans<<endl;
    return 0;
}