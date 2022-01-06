#include <bits/stdc++.h>

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

int dp[250][250];

int main() {
    setIO("248");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>dp[i][i];
    }
    int ans=0;
    for (int i=n;i>=0;i--){
        for (int j=i+1;j<n;j++){
            for (int k=i;k<=j;k++){
                if (dp[i][k]==dp[k+1][j]){
                    dp[i][j]=max(dp[i][j], dp[i][k]+1);
                }
            }
            ans=max(ans, dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

