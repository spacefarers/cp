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

int board[105][105];
map<int, bool> ans;
map<int, pair<pi, pi>> mp; // x1, x2, y1, y2
int n;

int main() {
    setIO("art");
    cin>>n;
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        for (int j=0;j<n;j++){
            board[i][j]=a[j]-'0';
            ans[board[i][j]]=true;
            mp[board[i][j]].f.f=0x7fffffff;
            mp[board[i][j]].s.f=0x7fffffff;
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            mp[board[i][j]].f.f=min(mp[board[i][j]].f.f, j);
            mp[board[i][j]].f.s=max(mp[board[i][j]].f.s, j);
            mp[board[i][j]].s.f=min(mp[board[i][j]].s.f, i);
            mp[board[i][j]].s.s=max(mp[board[i][j]].s.s, i);
        }
    }
    trav(z, mp){
        if (z.first==0) continue;
        for (int i=z.s.s.f;i<=z.s.s.s;i++){
            for (int j=z.s.f.f;j<=z.s.f.s;j++) {
                if (board[i][j]!=z.f) {
                    ans[board[i][j]]=false;
                }
            }
        }
    }
    int f_ans=0;
    trav(i, ans){
        if (i.f==0) continue;
//        cout<<i.f<<" "<<i.s<<endl;
        if (i.s) f_ans++;
    }
    cout<<f_ans<<endl;
    return 0;
}