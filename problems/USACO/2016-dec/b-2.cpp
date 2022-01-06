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

int n, ans[26], c_ans1[26], c_ans2[26];
vector<pair<string, string>> x;

int main() {
    setIO("blocks");
    cin>>n;
    for (int i=0;i<n;i++){
        string a, b;
        cin>>a>>b;
        x.emplace_back(a, b);
    }
    trav(u, x){
        memset(c_ans1, 0, sizeof(c_ans1));
        trav(i, u.first)
            c_ans1[i-'a']++;
        memset(c_ans2, 0, sizeof(c_ans2));
        trav(i, u.second)
            c_ans2[i-'a']++;
        for (int i=0;i<=25;i++)
            ans[i]+=max(c_ans1[i], c_ans2[i]);
    }
    for (int i=0;i<=25;i++)
        cout<<ans[i]<<endl;
    return 0;
}