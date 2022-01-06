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
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int occur[100005];
int main() {
    setIO("planting");
    int n;
    cin>>n;
    for (int i=1;i<n;i++){
        int a, b;
        cin>>a>>b;
        occur[a]++;
        occur[b]++;
    }
    int max_occur=0;
    for (int i=1;i<=n;i++){
        max_occur=max(max_occur, occur[i]);
    }
    cout<<max_occur+1<<endl;
    return 0;
}