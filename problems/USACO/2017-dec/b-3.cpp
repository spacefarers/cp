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
#include <algorithm>
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

int main() {
    setIO("measurement");
    int n;
    vector<pair<int, pair<int, int>>> logs;
//    char cows[3]={'B', 'E', 'M'};
    cin>>n;
    for (int i=1;i<=n;i++){
        int a, c, d=-1;
        string b;
        cin>>a>>b>>c;
        switch (b[0]) {
            case 'B':
                d=0;
                break;
            case 'E':
                d=1;
                break;
            case 'M':
                d=2;
                break;
        }
        logs.pb({a, {d, c}});
    }
    sort(all(logs));
    bool onboard[3];
    int production[3];
    production[0]=7;
    production[1]=7;
    production[2]=7;
    memset(onboard, true, sizeof(onboard));
    int ans=0;
//    cout<<production[0]<<endl;
    trav(log, logs){
//        cout<<log.second.first<<" "<<log.second.second<<endl;
        production[log.second.first]+=log.second.second;
        int max_p=max(max(production[0], production[1]), production[2]);
//        cout<<production[0]<<" "<<production[1]<<" "<<production[2]<<endl;
        if ((production[0]==max_p&&!onboard[0])||(production[1]==max_p&&!onboard[1])||(production[2]==max_p&&!onboard[2])||(production[0]!=max_p&&onboard[0])||(production[1]!=max_p&&onboard[1])||(production[2]!=max_p&&onboard[2])) ans++;
        onboard[0]=production[0]==max_p;
        onboard[1]=production[1]==max_p;
        onboard[2]=production[2]==max_p;
    }
    cout<<ans<<endl;
    return 0;
}