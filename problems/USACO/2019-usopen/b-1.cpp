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

int main() {
    setIO("buckets");
    pi start, end, block;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            char a;
            cin>>a;
            if (a=='B') start={i, j};
            else if (a=='L') end={i, j};
            else if (a=='R') block={i, j};
        }
    }
    int ans=abs(start.first-end.first)+abs(start.second-end.second)-1;
    if (start.first==end.first&&start.first==block.first){
        if ((block.second<start.second&&block.second>end.second)||(block.second>start.second&&block.second<end.second)){
            ans+=2;
        }
    }
    if (start.second==end.second&&start.second==block.second){
        if ((block.first<start.first&&block.first>end.first)||(block.first>start.first&&block.first<end.first)){
            ans+=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}