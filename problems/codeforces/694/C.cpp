#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, m;
        cin>>n>>m;
        vector<int> friends(n);
        vector<int> prices(m);
        for (int i=0;i<n;i++) cin>>friends[i];
        for (int i=0;i<m;i++) cin>>prices[i];
        long long ans=0;
        for (auto &i:friends){
            ans+=prices[i-1];
        }
        sort(friends.begin(), friends.end(), greater<int>());
        int cursor=0;
        for (auto &i:friends){
            if (i-1<=cursor) break;
            ans-=prices[i-1];
            ans+=prices[cursor++];
        }
        cout<<ans<<endl;
    }
}