#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cstring>

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
    setIO("photo");
    int n, a[1005], b[1005];
    bool c[1005];
    cin>>n;
    F0R(i, n-1){
        cin>>a[i];
        a[i];
    }
    FOR(i, 1, n+1){
        memset(c, false, sizeof(c));
        b[0]=i;
        c[i]=true;
        bool ok=true;
        FOR(j,1, n){
            int x = a[j-1]-b[j-1];
            if (c[x]||x<0||x>n) {
                ok=false;
                break;
            }
            b[j] = x;
            c[x]=true;
        }
        if(ok) break;
    }
    F0R(i, n){
        cout<<b[i]<<((i==n-1)?"":" ");
    }
    return 0;
}