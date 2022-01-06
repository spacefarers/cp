#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
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

vi in[200005], out[200005];
int count1=1, fav[200005];
map<int, int> mp;

void dfs(int x, bool type, int from){
    if (type){
        if (fav[x]!=0) return;
        fav[x]=count1;
        trav(i, in[x]){
            if (i!=from) dfs(i, !type, x);
        }
    } else{
        if (mp[from]!=0) fav[x]=mp[from];
        trav(i, out[x]){
            if (i!=from) dfs(i, !type, x);
        }
    }
}

int main() {
    setIO("fcolor");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        out[b].pb(a);
        in[a].pb(b);
    }
    mp[1]=2;
    for (int i=1;i<=n;i++){
        if (fav[i]==0) {
            dfs(i, true, 0);
            count1++;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<fav[i]<<endl;
    }
    return 0;
}

