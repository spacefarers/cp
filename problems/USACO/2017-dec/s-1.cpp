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
typedef vector<pair<int,int>> vpi;

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
//    setIO("homework");
    int n;
    cin>>n;
    int hws[100005];
    for (int i=0;i<n;i++){
//        cout<<i<<endl;
        cin>>hws[i];
    }
    int sums[100005];
    double ans[100005];
    int c_min=hws[n-1];
    for (int i=n-1;i>=0;i--){
        sums[i]=sums[i+1]+hws[i];
        c_min=min(c_min, hws[i]);
        if (i==n-1) continue;
        ans[i]=(double)(sums[i]-c_min)/(double)(n-i-1);
    }
    int ans_max=0;
    for (int i=1;i<n;i++){
        if (ans[i]>ans[ans_max]){
            ans_max=i;
        }
    }
    for (int i=1;i<n;i++){
        if (ans[i]==ans[ans_max]) cout<<i<<endl;
    }
    return 0;
}