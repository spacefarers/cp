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

vi initial_a, initial_b;
bool ans[2005];
int total_milk_a=1000, total_milk_b=1000, t_ans;

void dfs(int depth){
    if (depth==4){
        int sum=0;
        trav (i, initial_a){
            sum+=i;
        }
        if (!ans[sum]){
            ans[sum]=true;
            t_ans++;
        }
        return;
    }
    if (depth%2==0){
        for (int i=0;i<10;i++){
            int u=initial_a[i];
            initial_a.erase(initial_a.begin() + i);
            initial_b.pb(u);
            total_milk_a-=u;
            total_milk_b+=u;
            dfs(depth+1);
            initial_a.insert(initial_a.begin()+i, u);
            total_milk_b-=u;
            total_milk_a+=u;
            initial_b.pop_back();
        }
    } else {
        for (int i=0;i<10;i++){
            int u=initial_b[i];
            initial_b.erase(initial_b.begin() + i);
            initial_a.pb(u);
            total_milk_b-=u;
            total_milk_a+=u;
            dfs(depth+1);
            initial_b.insert(initial_b.begin()+i, u);
            total_milk_a-=u;
            total_milk_b+=u;
            initial_a.pop_back();
        }
    }
}

int main() {
    setIO("backforth");
    for (int i=1;i<=10;i++){
        int a;
        cin>>a;
        initial_a.pb(a);
    }
    for (int i=1;i<=10;i++){
        int b;
        cin>>b;
        initial_b.pb(b);
    }
    dfs(0);
    cout<<t_ans<<endl;
    return 0;
}