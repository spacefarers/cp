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

int main() {
    setIO("shuffle");
    int n;
    int order[105], ans[105], new_ans[105];
    string names[105];
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>order[i];
        ans[i]=order[i];
    }
    for (int i=1;i<=n;i++){
        cin>>names[i];
    }
    for (int i=1;i<=2;i++){
        for (int j=1;j<=n;j++){
            new_ans[j]=ans[order[j]];
        }
        for (int j=1;j<=n;j++){
            ans[j]=new_ans[j];
        }
    }
    for (int i=1;i<=n;i++){
        cout<<names[ans[i]]<<endl;
    }
    return 0;
}