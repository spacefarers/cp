/*
ID: michael419
LchangesNG: C++
TchangesSK:
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

int ans[100005], new_ans[100005], changes[35][100005];
ll n, k, m, b, c;


void apply(int x){
    for (int i=1;i<=n;i++){
        new_ans[i]=ans[changes[x][i]];
    }
    for (int i=1;i<=n;i++){
        ans[i]=new_ans[i];
    }
}

int main() {
    setIO("swap");
    vpi a;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        cin>>b>>c;
        a.pb({b, c});
    }
    for (int i=1;i<=n;i++){
        ans[i]=i;
        int x=i;
        trav(y, a){
            if (y.first<=x&&x<=y.second) {
                x=y.first+y.second-x;
            }
        }
        changes[0][x]=i;
    }
    for (int j=1;j<=n;j++){
        ans[j]=changes[0][j];
    }
    for (int i=0;i<30;i++){
        apply(i);
        for (int j=1;j<=n;j++){
            changes[i+1][j]=ans[j];
        }
    }
    int cc=30;
    for (int j=1;j<=n;j++){
        ans[j]=j;
    }
    while (k!=0){
//        cout<<k<<" "<<cc<<endl;
        if (k>=pow(2, cc)){
            k-=pow(2, cc);
            apply(cc);
        } else {
            cc--;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}