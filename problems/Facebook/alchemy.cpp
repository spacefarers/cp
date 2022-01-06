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
    setIO("input");
    int t;
    cin>>t;
    for (int k=1;k<=t;k++){
        cout<<"Case #"+to_string(k)+": ";
        int n;
        string a;
        cin>>n>>a;
        int c=0;
        trav(i, a){
            if (i=='B') c--;
            else c++;
        }
        if (abs(c)<=1) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}