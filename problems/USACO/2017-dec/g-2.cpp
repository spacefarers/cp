#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

vector<ll> paths[100005];
ll ans[100005][3], f_ans=0, mod=(1e9+7);
ll nodes[100005];
bool visited[100005];
bool special[100005];

void solve(int x){
    int c=0;
    trav(i, paths[x]){
        if (!visited[i]){
            c++;
            solve(i);
            ans[i][0]*=(ans[x][1]+ans[x][2])%mod;
            ans[i][1]*=(ans[x][2]+ans[x][0])%mod;
            ans[i][2]*=(ans[x][0]+ans[x][1])%mod;
        }
    }
    if (c==0) f_ans+=(ans[x][0]+ans[x][1]+ans[x][2])%mod;
}

int main() {
//    setIO("barnpainting");
    ll n, k, start_p=-1;
    cin>>n>>k;
    for (int i=1;i<n;i++){
        ans[i][0]=1;
        ans[i][1]=1;
        ans[i][2]=1;
        ll a, b;
        cin>>a>>b;
        paths[a].pb(b);
        paths[b].pb(a);
        nodes[a]++;
        nodes[b]++;
    }
    for (int i=1;i<=k;i++){
        ll a, b;
        cin>>a>>b;
        special[a]=true;
        ans[a][0]=0;
        ans[a][1]=0;
        ans[a][2]=0;
        ans[a][b-1]=1;
        start_p=a;
        trav (j, paths[a]){
            ans[j][b-1]=0;
        }
    }
    ll factor=1;
    bool ok=true;
    while (ok){
        ok=false;
        for (int i=1;i<=n;i++){
            if (nodes[i]==1&&!special[i]) {
                factor*=2;
                factor%=mod;
                visited[i]=true;
                nodes[i]=0;
                trav(j, paths[i]){
                    if (!visited[j])
                        nodes[j]--;
                }
                ok=true;
            }
        }
    }
    if (start_p==-1)
        f_ans=1;
    else
        solve(start_p);
    cout<<(f_ans*factor)%mod<<endl;
    return 0;
}