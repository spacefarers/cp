/*
ID: michael419
LANG: C++
TASK: frac1
*/

#include <iostream>
#include <set>

using namespace std;

#define f first
#define s second

void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    setIO("frac1");
    int n;
    cin>>n;
    auto cmp=[](pair<int, int> a, pair<int, int> b) {return a.f*b.s<b.f*a.s;};
    set<pair<int, int>, decltype(cmp)> fracs(cmp);
    for (int i=1;i<=n;i++){
        for (int j=0;j<=i;j++){
            fracs.insert({j/gcd(i, j), i/gcd(i, j)});
        }
    }
    for (auto &i:fracs){
        cout<<i.f<<"/"<<i.s<<endl;
    }
}
