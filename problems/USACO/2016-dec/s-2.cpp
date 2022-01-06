#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
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

map<string, int> mp;

int main() {
    setIO("citystate");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        string a, b;
        cin>>a>>b;
        a=a.substr(0, 2);
        if (a!=b)
            mp[a+b]++;
    }
    int ans=0;
    trav(u, mp){
        auto i=u.first;
        string a=i.substr(0, 2);
        string b=i.substr(2, 2);
        ans+=mp[i]*mp[b+a];
    }
    cout<<ans/2<<endl;
    return 0;
}