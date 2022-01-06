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
    setIO("shell");
    int n;
    vector<pair<pair<int, int>, int>> q;
    cin>>n;
    for (int i=1;i<=n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        q.pb({{a, b}, c});
    }
    int ans=0;
    for (int i=1;i<=3;i++){
        int c_ans=0;
        int pos=i;
        trav (a, q){
            if (pos==a.first.first) pos=a.first.second;
            else if (pos==a.first.second) pos=a.f.f;
            if (a.second==pos)c_ans++;
        }
        ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}