// created on 2021/7/3 by spacefarers
// problem: E. Advertising Agency

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll NCR[1005][1005],MOD=1e9+7;

void precomp(){
    NCR[0][0]=1;
    for (int i=1;i<1005;i++){
        NCR[i][0]=NCR[i][i]=1;
        for (int j=1;j<i;j++){
            NCR[i][j]=NCR[i-1][j-1]+NCR[i-1][j];
            NCR[i][j]%=MOD;
        }
    }
}

int main(){
    int t;
    cin>>t;
    precomp();
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<int> nums;
        for (int i=0;i<n;i++){
            int a;
            cin>>a;
            nums.push_back(a);
        }
        sort(nums.begin(),nums.end(),greater<>());
        int tot=0,first=-1;
        for (int i=0;i<n;i++){
            if (nums[i]==nums[k-1]){
                if (first==-1) first=i;
                tot++;
            }
        }
        cout<<NCR[tot][k-first]<<endl;
    }
}