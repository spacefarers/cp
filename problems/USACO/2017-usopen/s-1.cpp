#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
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

int times[100005], left_ones[100005], n, m=0, ids[100005];

bool cmp(int x, int y){
    return times[x]<times[y];
}

int main() {
    setIO("pairup");
    cin>>n;
    for (int i=0;i<n;i++){
        ids[i]=i;
        cin>>left_ones[i]>>times[i];
        m+=left_ones[i];
    }
    sort(ids, ids+n, cmp);
    int ans=0, left=0, right=n-1;
    while (left!=right){
        int num=min(left_ones[ids[left]], left_ones[ids[right]]);
        left_ones[ids[left]]-=num;
        left_ones[ids[right]]-=num;
        ans=max(ans, times[ids[left]]+times[ids[right]]);
        if (left_ones[ids[left]]==0) left++;
        if (left_ones[ids[right]]==0) right--;
    }
    ans=max(ans, 2*times[ids[left]]);
    cout<<ans<<endl;
    return 0;
}