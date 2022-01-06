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

int n, b;
int snow[300], b_h[300], b_l[300], dp[300];

int main() {
    setIO("snowboots");
    cin>>n>>b;
    for (int i=0;i<n;i++){
        cin>>snow[i];
    }
    for (int i=0;i<b;i++){
        cin>>b_h[i]>>b_l[i];
    }
    memset(dp, 0x7f, sizeof(dp));
    dp[0]=0;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            for (int a=dp[j];a<b;a++){
                if (b_l[a]>=i-j&&b_h[a]>=snow[i]&&b_h[a]>=snow[j]) {
                    dp[i]=min(dp[i], a);
                }
            }
        }
    }
//    ll pos=0;
//    int i=0;
//    while (pos<n-1){
//        if (b_h[i]<snow[pos]){
//            i++;
//            continue;
//        }
//        bool leaped=false;
//        for (int j=b_l[i];j>=1;j--){
//            if (snow[pos+j]<=b_h[i]){
//                pos+=j;
//                leaped=true;
//                break;
//            }
//        }
//        if (!leaped) i++;
//    }
    cout<<dp[n-1]<<endl;
    return 0;
}