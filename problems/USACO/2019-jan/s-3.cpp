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
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

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

int pos[100005], neg[100005], id[100005];

bool cmp(int x, int y){
    if (pos[x]==pos[y])
        return neg[x]<neg[y];
    return pos[x]>pos[y];
}

int main() {
    setIO("mountains");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        pos[i]=a+b;
        neg[i]=a-b;
        id[i]=i;
    }
    sort(id, id+n, cmp);
    int cnt=0x7fffffff;
    int ans=0;
    for (int i=0;i<n;i++){
        if (neg[id[i]]<cnt){
            ans++;
            cnt = neg[id[i]];
        }
    }
    cout<<ans<<endl;
    return 0;
}