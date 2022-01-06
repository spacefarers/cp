/*
ID: michael419
LANG: C++
TASK:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
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
int n;
vector<pair<int, pair<int, int>>> cows;
int gotto=1;


struct cmp{
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y){
        return x.second.second>y.second.second;
    }
};

int main() {
    setIO("convention2");
    cin>>n;
    for (int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        cows.pb({a, {b, i}});
    }
    sort(all(cows));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> q;
    q.push(cows[0]);
    int c_time=cows[0].first, ans=0;
    while (true){
        if (!q.empty()){
            auto e=q.top();
            q.pop();
            ans=max(ans, c_time-e.first);
            c_time+=e.second.first;
            int i;
            for (i=gotto;i<n;i++){
                if (cows[i].first<=c_time)
                    q.push(cows[i]);
                else break;
            }
            gotto=i;
        } else {
            if (gotto>=n) break;
            auto e=cows[gotto++];
            c_time=e.first+e.second.first;
            int i;
            for (i=gotto;i<n;i++){
                if (cows[i].first<=c_time)
                    q.push(cows[i]);
                else break;
            }
            gotto=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}