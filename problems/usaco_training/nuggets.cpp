/*
ID: michael419
LANG: C++
TASK: nuggets
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

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

bool dp[256];

int main(){
    setIO("nuggets");
    int n;
    cin>>n;
    int gcd1=-1;
    vector<int> nums;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
        if (gcd1==-1) gcd1=a;
        else gcd1=gcd(gcd1, a);
    }
    if (gcd1>1){
        cout<<0<<endl;
        exit(0);
    }
    sort(nums.begin(), nums.end());
    int ans=0, cur=0;
    dp[0]=true;
    while (cur-ans<=256){
        if (!dp[cur%256]) ans=cur;
        else {
            dp[cur%256]=false;
            for (auto &i:nums){
                dp[(cur+i)%256]=true;
            }
        }
        cur++;
    }
    cout<<ans<<endl;
}