#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        vector<int> price(3), amount(3);
        for (int i=0;i<3;i++) cin>>price[i];
        for (int i=0;i<3;i++) cin>>amount[i];
        sort(price.begin(), price.end());
        sort(amount.begin(), amount.end());
        int ans=0;
        for (int i=0;i<3;i++) ans+=price[i]*amount[i];
        cout<<ans<<endl;
    }
}