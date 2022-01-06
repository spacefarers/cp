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

ll storage[3], hold[3], bp[3];

void next(ll x){
    ll u=(x+1)%3;
    ll move=min(hold[u]-storage[u], storage[x]);
    storage[x]-=move;
    storage[u]+=move;
}

int main() {
    setIO("mixmilk");
    cin>>hold[0]>>storage[0]>>hold[1]>>storage[1]>>hold[2]>>storage[2];
    for (int i=0;i<=99;i++){
        next(i%3);
    }
    cout<<storage[0]<<endl<<storage[1]<<endl<<storage[2]<<endl;
    return 0;
}