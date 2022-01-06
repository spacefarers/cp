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

vector<ll> cows;
ll b_pos=0, last_val=0, b_val=0, n, where=0, c=0;

int main() {
    setIO("outofplace");
    cin>>n;
    cows.rsz(n);
    for (int i=0;i<n;i++){
        cin>>cows[i];
    }
    bool rev=false;
    for (int i=1;i<n;i++){
        if (cows[i]<cows[i-1]){
            if ((i>=2&&cows[i]>cows[i-2])||(i!=n-1&&cows[i-1]>cows[i+1])){
                rev=true;
                b_pos=i-1;
                b_val=cows[i-1];
                break;
            }
            b_pos=i;
            b_val=cows[i];
            break;
        }
    }
    where=n-1;
    for (int i=0;i<n;i++){
        if (rev&&cows[i]==b_val&&i!=b_pos){
            where=i;
            break;
        }
        if (cows[i]>b_val) {
            where=i;
            break;
        }
    }
    last_val=0;
    if (where>b_pos){
        rev=true;
        ll temp=b_pos;
        b_pos=where;
        where=temp;
    }
    for (int i=where;i<b_pos;i++){
        if (rev&&i==where) continue;
        if (cows[i]!=last_val) {
            c++;
            last_val=cows[i];
        }
    }
    cout<<c<<endl;
    return 0;
}