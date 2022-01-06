#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
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

ll n, p;
bool visited[1005];
vector<pair<ll, ll>> x;

int dfs(int i){
    if (visited[i]) return 0;
    visited[i]=true;
    int ans=1;
    for (int j=0;j<n;j++){
        if (!visited[j]&&pow(x[i].f-x[j].f, 2)+pow(x[i].s-x[j].s, 2)<=p)
            ans+=dfs(j);
    }
    return ans;
}

bool validate(){
    for (int i=0;i<n;i++){
        memset(visited, false, sizeof(visited));
        if (dfs(i)!=n) return false;
    }
    return true;
}

int main() {
//    setIO("moocast");
    cin>>n;
    for (int i=0;i<n;i++){
        ll a, b;
        cin>>a>>b;
        x.emplace_back(a, b);
    }
    ll left=0, right=1e18;
    while (left<=right){
        ll mid=(left+right+1)/2;
        p=mid;
        if (validate()){
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    cout<<left<<endl;
    return 0;
}