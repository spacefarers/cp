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

vpi gestures;

int main() {
    setIO("hps");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        if (a!=b)
            gestures.emplace_back(a, b);
    }
//    1>2>3>1
    int c_ans=0;
    trav(i, gestures){
        if (i.first==1&&i.second==2||i.first==2&&i.second==3||i.first==3&&i.second==1) c_ans++;
    }
//    1>3>2>1
    int c_ans2=0;
    trav(i, gestures){
        if (i.first==1&&i.second==3||i.first==3&&i.second==2||i.first==2&&i.second==1) c_ans2++;
    }
    cout<<max(c_ans2, c_ans)<<endl;
    return 0;
}