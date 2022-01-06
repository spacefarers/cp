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

int n, num=0;
bool visited[205];
vector<pair<int, pair<int, int>>> x;
int ans[205];

void dfs(int i){
    if (visited[i]) return;
    visited[i]=true;
    ans[num]++;
    for (int j=0;j<n;j++){
        if (sqrt(pow(x[i].s.f-x[j].s.f, 2)+pow(x[i].s.s-x[j].s.s, 2))<=x[i].f)
            dfs(j);
    }
}

int main() {
    setIO("moocast");
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        x.emplace_back(c, make_pair(a, b));
    }
    for (int i=0;i<n;i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        num++;
    }
    int f_ans=0;
    trav(i, ans){
        f_ans=max(f_ans, i);
    }
    cout<<f_ans<<endl;
    return 0;
}