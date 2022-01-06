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
int n;
map<string, map<int, bool>> mp;
vector<string> cows[105];

int main() {
    setIO("guess");
    cin>>n;
    for (int i=1;i<=n;i++){
        string name;
        int x;
        cin>>name>>x;
        for (int j=1;j<=x;j++) {
            string a;
            cin>>a;
            cows[i].pb(a);
            mp[a][i]=true;
        }
    }
    int ans=0;
    for (int i=1; i<=n;i++){
        int c_ans=0;
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            int c_c_ans=1;
            trav(a, cows[i]){
                if (mp[a][j]) c_c_ans++;
            }
            c_ans=max(c_ans, c_c_ans);
        }
        ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}