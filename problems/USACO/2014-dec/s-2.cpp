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

int dp[505][505];

int main() {
//    setIO("marathon");
    int N, K;
    cin>>N>>K;
    vpi points;
    for (int i=0;i<N;i++){
        int a, b;
        cin>>a>>b;
        points.pb({a, b});
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0][0]=0;
    for (int i=0;i<=K;i++){
        for (int j=0;j<N;j++){
            for (int l=j+1;l<N&&i+(l-j-1)<=K;l++){
                int nexti=i+(l-j-1);
                int nextj=l;
                dp[nexti][nextj]=min(dp[nexti][nextj], dp[i][j]+abs(points[j].f-points[l].f)+abs(points[j].s-points[l].s));
            }
        }
    }
    cout<<dp[K][N-1]<<endl;
    return 0;
}

