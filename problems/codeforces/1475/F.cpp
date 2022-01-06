#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int triangle[1005][1005], mod=1e9+7;

int main(){
    int t;
    cin>>t;
    while (t--){
        int n, k;
        cin>>n>>k;
        triangle[1][1]=1;
        for (int i=2;i<=n;++i){
            for (int j=1;j<=i;++j){
                triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
                triangle[i][j]%=mod;
            }
        }
        map<int, int, greater<int>> nums;
        for (int i=0;i<n;++i){
            int a;
            cin>>a;
            nums[a]++;
        }
        bool ok=true;
        for (auto &i:nums){
            if (k<=i.second){
                cout<<triangle[i.second+1][k+1]<<endl;
                ok=false;
                break;
            } else k-=i.second;
        }
        if (ok) cout<<1<<endl;
    }
}