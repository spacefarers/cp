/*
ID: michael419
LANG: C++11
TASK: ariprog
*/

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

bool hit[200000];

int main() {
    setIO("ariprog");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<=m;i++){
        for (int j=0;j<=m;j++){
            hit[i*i+j*j]=true;
        }
    }
    bool ook=false;
    vpi ans;
    for (int j=0;j<=(2*m*m);j++){
        for (int i=1;j+(n-1)*i<=(2*m*m);i++){
            bool ok=true;
            for (int k=0;k<n;k++){
                if (!hit[j+i*k]) {ok=false; break;}
            }
            if (ok){
                ook=true;
                ans.emplace_back(i, j);
            }
        }
    }
    sort(all(ans));
    trav(i, ans){
        cout<<i.s<<" "<<i.f<<endl;
    }
    if (!ook) cout<<"NONE"<<endl;
    return 0;
}

