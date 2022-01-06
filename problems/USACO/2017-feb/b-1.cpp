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

int cows[100];

int main() {
    setIO("crossroad");
    memset(cows, -1, sizeof(cows));
    int n, ans=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        if (cows[a]!=-1){
            if (cows[a]!=b){
                ans++;
            }
        }
        cows[a]=b;
    }
    cout<<ans<<endl;
    return 0;
}