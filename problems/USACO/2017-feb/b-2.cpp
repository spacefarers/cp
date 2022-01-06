#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

vpi pairs;
map<char, bool> exceptions;

int main() {
    setIO("circlecross");
    string a;
    cin>>a;
    for (int i=0;i<52;i++){
        for (int j=i+1;j<52;j++){
            if (a[i]==a[j]) pairs.pb({i, j});
        }
    }
    int ans=0;
    trav(i, pairs){
//        cout<<i.f<<" "<<i.s<<endl;
        exceptions.clear();
        for (int x=i.f+1;x<i.s;x++){
            exceptions[a[x]]=!exceptions[a[x]];
        }
        trav (x, exceptions){
            if (x.s) ans++;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}