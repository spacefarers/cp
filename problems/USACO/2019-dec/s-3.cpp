/*
ID: michael419
LANG: C++
TASK: milkvisits
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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
#define last(x) x[sz(x)-1]
#define f first
#define s second
#define debug_vi(x) trav(o, x) cout<<o<<" ";

char cow[100005];
vi paths[100005];
int parts[100005], num;

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

void dfs(int x){
    parts[x] = num;
    trav(a, paths[x]){
        if (cow[a]==cow[x]) dfs(a);
    }
}

int main() {
    setIO("milkvisits");
    int n, m, a, b;
    char c;
    cin>>n>>m;
    FOR(i, 1, n+1){
        cin>>cow[i];
    }
    F0R(i, n-1){
        cin>>a>>b;
        paths[a].pb(b);
    }
    F0R(i, n){
        if (!parts[i]){
            num++;
            dfs(i);
        }
    }
    F0R(i, m){
        cin>>a>>b>>c;
        if (parts[a]==parts[b]&&cow[a]!=c) cout<<0;
        else cout<<1;
    }
    return 0;
}