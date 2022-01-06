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

bool cows[15][15];

void action(int y, int x){
    for (int i=0;i<=y;i++){
        for (int j=0;j<=x;j++){
            cows[i][j]=!cows[i][j];
        }
    }
}

int main() {
    setIO("cowtip");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        for (int j=0;j<n;j++){
            cows[i][j]=a[j]=='1';
        }
    }
    int ans=0;
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;j--){
            if (cows[i][j]){
                ans++;
                action(i, j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}