// created on 6/19/21 by spacefarers
// problem: 1569：【例1】石子合并
// range dp

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll dp_min[405][405],dp_max[405][405],nums[405];

int main(){
    int n;
    cin>>n;
    memset(dp_min,0x3f,sizeof dp_min);
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        nums[i]=nums[i+n]=a;
    }
    for (int i=1;i<=2*n;i++){
        dp_min[i][i]=dp_max[i][i]=0;
    }
    for (int i=2*n;i>0;i--){
        for (int j=i+1;j<=2*n;j++){
            ll add=0;
            for (int k=i;k<j;k++){
                add+=nums[k];
                dp_min[i][j]=min(dp_min[i][k]+dp_min[k+1][j],dp_min[i][j]);
                dp_max[i][j]=max(dp_max[i][k]+dp_max[k+1][j],dp_max[i][j]);
            }
            add+=nums[j];
            dp_min[i][j]+=add;
            dp_max[i][j]+=add;
        }
    }
    ll min_ans=1e15,max_ans=0;
    for (int i=1;i<=n;i++){
        min_ans=min(min_ans,dp_min[i][i+n-1]);
        max_ans=max(max_ans,dp_max[i][i+n-1]);
    }
    cout<<min_ans<<endl<<max_ans<<endl;
}