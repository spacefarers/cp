#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;

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

int n, g;
vector<pair<int, pair<int, int>>> logs;

int main() {
    setIO("measurement");
    cin>>n>>g;
    for (int i=1;i<=n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        logs.pb({a, {b, c}});
    }
    sort(all(logs));
    vpi q;
    q.pb({g, -1});
    q.pb({g, -1});
    q.pb({g, -1});
    int ans=0;
    map<int, int> mp;
    map<int, int, greater<int>> count;
    count[0]=n+1;
    trav(log, logs){
        int& r = mp[log.second.first];
        bool was_top = r==count.begin()->first;
        int pre_count=count[r]--;
        if (count[r]==0) count.erase(r);
        r+=log.second.second;
        int c_count=++count[r];
        bool is_top=r==count.begin()->first;
        if (was_top){
            if (!is_top||pre_count!=1||c_count!=1) ans++;
        } else if (is_top) ans++;
    }
    cout<<ans<<endl;
    return 0;
}