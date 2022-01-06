/*
ID: michael419
LANG: C++11
TASK: milk3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
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

bool visited[21][21][21];
int A, B, C;

void dfs(int a, int b, int c){
    if (visited[a][b][c]) return;
    visited[a][b][c]=true;
    int a2b = min(a, B-b);
    dfs(a-a2b, b+a2b, c);
    int b2a = min(b, A-a);
    dfs(a+b2a, b-b2a, c);
    int a2c = min(a, C-c);
    dfs(a-a2c, b, c+a2c);
    int c2a = min(A-a, c);
    dfs(a+c2a, b, c-c2a);
    int b2c = min(b, C-c);
    dfs(a, b-b2c, c+b2c);
    int c2b = min(c, B-b);
    dfs(a, b+c2b, c-c2b);
}

int main() {
    setIO("milk3");
    cin>>A>>B>>C;
    set<int> ss;
    dfs(0, 0, C);
    for (int i=0;i<=C;i++){
        if (visited[0][i][C-i]) ss.insert(C-i);
    }
    cout<<*ss.begin();
    ss.erase(ss.begin());
    trav(i, ss){
        cout<<" "<<i;
    }
    cout<<endl;
    return 0;
}

