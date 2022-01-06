#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

vector<string> spotted;
vector<string> no_spot;
map<char, bool> spots;

int main() {
    setIO("cownomics");
    int n, m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        spotted.pb(a);
    }
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        no_spot.pb(a);
    }
    int ans=0;
    for (int i=0;i<m;i++){
        bool ok=true;
        spots.clear();
        trav(j, spotted){
            spots[j[i]]=true;
        }
        trav(j, no_spot){
            if (spots[j[i]]){
                ok=false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}