#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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

int n, m;
string spotted[505], no_spots[505];
bool check[10005];

int main() {
    setIO("cownomics");
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>spotted[i];
    }
    for(int i=0;i<n;i++){
        cin>>no_spots[i];
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for (int j=i+1;j<m;j++){
            for (int k=j+1;k<m;k++){
                memset(check, false, sizeof(check));
                for (int a=0;a<n;a++){
                    check[100*spotted[a][i]+10*spotted[a][j]+spotted[a][k]]=true;
                }
                bool ok=true;
                for (int a=0;a<n;a++){
                    if (check[100*no_spots[a][i]+10*no_spots[a][j]+no_spots[a][k]]) ok=false;
                }
                if (ok) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}