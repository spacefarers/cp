//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include <queue>
//#include <map>
//#include <set>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<ll> vl;
//typedef pair<int,int> pi;
//typedef pair<ll,ll> pl;
//typedef vector<pi> vpi;
//typedef vector<pl> vpl;
//typedef vector<vi> vvi;
//typedef vector<vl> vvl;
//
//#define trav(a,x) for (auto& a: x)
//
//#define pb push_back
//#define rsz resize
//#define sz(x) int(x.size())
//#define all(x) begin(x), end(x)
//#define f first
//#define s second
//
//
//void setIO(const string& name) {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    freopen((name+".in").c_str(),"r",stdin);
//    freopen((name+".out").c_str(),"w",stdout);
//}
//
//map<pi, int> board;
//int ans[1005][1005];
//bool has_s[1005][1005];
//map<pi, pair<pair<bool, bool>, pair<bool, bool>>> visited;
//
//void dfs(pi to, int from, bool has_smell, int dep){
//    if (board[to]==0||(board[to]==3&&!has_smell)) return;
////    switch (from) {
////        default:
////            break;
////        case 0:
////            if (visited[to].f.f) return;
////            visited[to].f.f=true;
////            break;
////        case 1:
////            if (visited[to].f.s) return;
////            visited[to].f.s=true;
////            break;
////        case 2:
////            if (visited[to].s.f) return;
////            visited[to].s.f=true;
////            break;
////        case 3:
////            if (visited[to].s.s) return;
////            visited[to].s.s=true;
////            break;
////    }
//    if (dep>=ans[to.f][to.s]&&(!has_smell||has_s[to.f][to.s])) return;
//    has_s[to.f][to.s]=has_smell;
//    ans[to.f][to.s]=dep;
//    if (board[to]==2) has_smell=true;
//    if (board[to]==4){
//        auto temp=to;
//        if (from==0) temp.s++;
//        else if (from==1) temp.f--;
//        else if (from==2) temp.f++;
//        else if (from==3) temp.s--;
//        dfs(temp, from, false, dep+1);
//    } else {
//        dfs({to.f, to.s+1}, 0, has_smell, dep+1);
//        dfs({to.f-1, to.s}, 1, has_smell, dep+1);
//        dfs({to.f+1, to.s}, 2, has_smell, dep+1);
//        dfs({to.f, to.s-1}, 3, has_smell, dep+1);
//    }
//}
//
//int main() {
////    setIO("dream");
//    int n, m;
//    cin>>n>>m;
//    memset(ans, 0x7f, sizeof ans);
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++){
//            int a;
//            cin>>a;
//            board[{i, j}]=a;
//        }
//    }
//    dfs({1, 1}, 0, false, 0);
//    dfs({1, 1}, 1, false, 0);
//    dfs({1, 1}, 2, false, 0);
//    dfs({1, 1}, 3, false, 0);
//    if (ans[n][n]>10000000) ans[n][n]=-1;
//    cout<<ans[n][n]<<endl;
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

map<pi, int> mp;
map<pi, int> dist;
map<pi, bool> has_smell;

int main() {
//    setIO("dream");
    int n, m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int a;
            cin>>a;
            mp[{i, j}]=a;
            dist[{i, j}]=0x7fffffff;
        }
    }
    priority_queue<pair<int, pair<pi, pair<bool, int>>>, vector<pair<int, pair<pi, pair<bool, int>>>>, greater<pair<int, pair<pi, pair<bool, int>>>>> q;
    q.push({0, {{1, 1}, {false, 0}}});
    dist[{1, 1}]=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (dist[u.s.f]!=u.f) continue;
        if (mp[u.s.f]==0) continue;
        if (mp[u.s.f]==3&&!u.s.s.f) continue;
        if (mp[u.s.f]==2) u.s.s.f=true;
        if (u.f>=dist[u.s.f]&&(has_smell[u.s.f]||!u.s.s.f)) continue;
        dist[u.s.f]=u.f;
        has_smell[u.s.f]=u.s.s.f;
        if (mp[u.s.f]==4){
            switch (u.s.s.s) {
                default: break;
                case 0: q.push({u.f+1, {{u.s.f.f, u.s.f.s+1}, u.s.s}}); break;
                case 1: q.push({u.f+1, {{u.s.f.f, u.s.f.s-1}, u.s.s}}); break;
                case 2: q.push({u.f+1, {{u.s.f.f+1, u.s.f.s}, u.s.s}}); break;
                case 3: q.push({u.f+1, {{u.s.f.f-1, u.s.f.s}, u.s.s}}); break;
            }
        } else {
            u.s.s.s=0;
            q.push({u.f+1, {{u.s.f.f, u.s.f.s+1}, u.s.s}});
            u.s.s.s=1;
            q.push({u.f+1, {{u.s.f.f, u.s.f.s-1}, u.s.s}});
            u.s.s.s=2;
            q.push({u.f+1, {{u.s.f.f+1, u.s.f.s}, u.s.s}});
            u.s.s.s=3;
            q.push({u.f+1, {{u.s.f.f-1, u.s.f.s}, u.s.s}});
        }
    }
    cout<<dist[{n, n}]<<endl;
    return 0;
}