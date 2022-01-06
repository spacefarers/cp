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
    setIO("lostcow");
    int x, y, ans=0;
    cin>>x>>y;
    int x1=x;
    bool way=x<y;
    while (x1<y==way&&x1!=y){
        int dist=x1-x;
        dist*=3;
        if (dist==0) dist=-1;
        x1-=dist;
//        cout<<x1<<endl;
        ans+=abs(dist);
    }
    cout<<ans-abs(x1-y)<<endl;
    return 0;
}