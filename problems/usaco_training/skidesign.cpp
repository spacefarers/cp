/*
ID: michael419
LANG: C++11
TASK: skidesign
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


int n;
vi hills;

int v(int x){
    int ans=0;
    trav(i, hills){
        if (i<x) ans+=pow(x-i, 2);
        else if (i>x+17) ans+=pow(i-x-17, 2);
    }
    return ans;
}

int main() {
    setIO("skidesign");
    cin>>n;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        hills.pb(a);
    }
    sort(all(hills));
    int x=-1000;
    for (int b=200;b>=1;b/=2){
        while (v(x+b)>v(x+b+1)) x+=b;
    }
    cout<<v(x+1)<<endl;
    return 0;
}

