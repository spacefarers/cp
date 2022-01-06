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
#include <algorithm>

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


int n, m, c, max_t=0;
vi times;

bool validate(int x){
    int c_needed=0, last_p=c, last_st=0;
    trav(i, times){
        if (last_p==c||i-last_st>x){
            c_needed++;
            last_p=1;
            last_st=i;
        } else {
            last_p++;
        }
    }
    return c_needed>m;
}

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int main() {
    setIO("convention");
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++){
        int t;
        cin>>t;
        max_t=max(max_t, t);
        times.pb(t);
    }
    sort(all(times));
    int left=0, right=max_t;
    while (left<right){
        int mid=(left+right+1)/2;
        if (validate(mid)){
            left=mid;
        } else {
            right=mid-1;
        }
    }
    cout<<left+1<<endl;
    return 0;
}