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
//    setIO("berries");
    int a, b, d;
    cin>>a>>b;
    vi c;
    for (int i=1;i<=a;i++){
        cin>>d;
        c.push_back(d);
    }
    sort(all(c), greater<int>());
    int best_ans=0;
    for (int z=1;z<=c[0];z++){
        int e=0, be=0;
        priority_queue<int, vector<int>> q;
        trav(u, c){
            int t=u;
            while (t>z) {
                q.push(z);
                t-=z;
            }
            q.push(t);
        }
        for (int i=0;i<b/2;i++){
//            cout<<q.top()<<" ";
            q.pop();
        }
        int ans=0;
        for (int i=0;i<b/2;i++){
//            cout<<q.top()<<" ";
            ans+=q.top();
            q.pop();
        }
//        cout<<endl;
        best_ans = max(best_ans, ans);
    }
    cout<<best_ans<<endl;
    return 0;
}