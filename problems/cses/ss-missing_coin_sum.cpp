#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coins;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }
    sort(coins.begin(), coins.end());
    long long ans=1;
    for (int i=0;i<n&&ans>=coins[i];i++){
        ans+=coins[i];
    }
    cout<<ans<<endl;
}