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

int sums[100005][3], n;

int main() {
    setIO("hps");
    cin>>n;
    for (int i=1;i<=n;i++){
        sums[i][0]=sums[i-1][0];
        sums[i][1]=sums[i-1][1];
        sums[i][2]=sums[i-1][2];
        char a;
        cin>>a;
        switch (a) {
            default:
                break;
            case 'P':
                sums[i][0]++;
                break;
            case 'H':
                sums[i][1]++;
                break;
            case 'S':
                sums[i][2]++;
                break;
        }
    }
    int ans=0;
    for (int i=0;i<=n;i++){
        int c_ans=max(max(sums[i][0], sums[i][1]), sums[i][2]);
        c_ans+=max(max(sums[n][0]-sums[i][0], sums[n][1]-sums[i][1]), sums[n][2]-sums[i][2]);
        ans=max(ans, c_ans);
    }
    cout<<ans<<endl;
    return 0;
}