/*
ID: michael419
LANG: C++
TASK: humble
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

int max_num[105];

int main(){
    setIO("humble");
    int k, n;
    cin>>k>>n;
    set<int> primes;
    vector<int> ans;
    memset(max_num, 0, sizeof max_num);
    for (int i=0;i<k;i++){
        int a;
        cin>>a;
        primes.insert(a);
    }
    int last_one=1;
    ans.push_back(1);
    for (int i=0;i<n;i++){
        int min_one=0x7fffffff;
        int u=0;
        for (auto &j:primes){
            while (j*ans[max_num[u]]<=last_one) max_num[u]++;
            min_one=min(min_one, j*ans[max_num[u]]);
            u++;
        }
        ans.push_back(min_one);
        last_one=min_one;
    }
    cout<<last_one<<endl;
}
