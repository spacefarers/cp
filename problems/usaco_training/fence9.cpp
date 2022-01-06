/*
ID: michael419
LANG: C++
TASK: fence9
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int roundup(double a){
    int b=int(floor(a));
    if (a-b>1e-6) b++;
    return b;
}

int rounddown(double a){
    int b=int(ceil(a));
    if (b-a>1e-6) b--;
    return b;
}

int main(){
    setIO("fence9");
    int n, m, p;
    cin>>n>>m>>p;
    double k1=(double)n/m;
    double k2=(double)(n-p)/m;
    int ans=0;
    for (int i=1;i<m;i++){
        int high_lim=roundup(k2*i+p);
        int low_lim=rounddown(k1*i);
        ans+=(high_lim-low_lim-1);
    }
    cout<<ans<<endl;
}