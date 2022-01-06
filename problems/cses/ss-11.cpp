#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

int main() {
//    setIO("");
    int n;
    cin>>n;
    vi cubes(n);
    for (int i=0;i<n;i++){
        cin>>cubes[i];
    }
    multiset<int> existing;
    trav (i, cubes){
        auto a=existing.upper_bound(i);
        if (a==existing.end()){
            existing.insert(i);
        } else {
            existing.erase(a);
            existing.insert(i);
        }
    }
    cout<<existing.size()<<endl;
    return 0;
}