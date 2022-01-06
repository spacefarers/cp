/*
ID: michael419
LANG: C++
TASK: fact4
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

int main(){
    setIO("fact4");
    int n;
    cin>>n;
    int five_counts=0;
    for (int i=1;i<=n;i++){
        int u=i;
        while (u%5==0) {
            u/=5;
            five_counts++;
        }
    }
    int ans=1;
    for (int i=1;i<=n;i++){
        int u=i;
        while (u%5==0){
            u/=5;
        }
        while (u%2==0&&five_counts>0){
            u/=2;
            five_counts--;
        }
        ans*=u;
        ans%=10;
    }
    cout<<ans<<endl;
}