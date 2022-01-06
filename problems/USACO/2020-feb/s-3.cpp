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
int n, val[5000], d[5000], h=0, e=0, f=0, g=0;
vi a[5000];

void dfs(int x, int depth, int previous){
    d[x]=depth;
    trav(i, a[x]){
        if (i!=previous){
            dfs(i, depth+1, x);
        }
    }
}

int main() {
//    setIO("clocktree");
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>val[i];
    }
    for (int i=1;i<n;i++){
        int c, b;
        cin>>c>>b;
        a[c].pb(b);
        a[b].pb(c);
    }
    dfs(1, 0, -1);
    for (int i=1;i<=n;i++){
        if (d[i]%2){
            e+=val[i];
            g++;
        } else {
            f+=val[i];
            h++;
        }
    }
    if (e%12==f%12){
        cout<<n<<endl;
    } else if ((e+1)%12==f%12){
        cout<<h<<endl;
    } else if (e%12==(f+1)%12){
        cout<<g<<endl;
    } else {
        cout<<0<<endl;
    }
    return 0;
}