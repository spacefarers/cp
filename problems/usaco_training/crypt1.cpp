/*
ID: michael419
LANG: C++11
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
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

map<char, bool> dict;

bool validate(int a){
    string b=to_string(a);
    trav(i, b){
        if (!dict[i]) return false;
    }
    return true;
}

int main() {
    setIO("crypt1");
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        char a;
        cin>>a;
        dict[a]=true;
    }
    int ans=0;
    for (int i=100;i<=999;i++){
        for(int j=10;j<=99;j++){
            if (!validate(i)||!validate(j)||!validate(j%10*i)||!validate(j/10*i)||!validate(j*i)||j/10*i>999||j%10*i>999||j*i>9999) continue;
//            cout<<i<<" "<<j<<endl;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}