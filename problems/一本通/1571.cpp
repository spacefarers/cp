// created on 2021/6/21 by spacefarers
// problem: 1571：【例 3】凸多边形的划分

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll weight[105],dp[105][105];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        weight[i]=weight[i+n]=a;
    }
    for (int i=2*n;i>0;i++){
        for (int j=i+1;j<=2*n;j++){
            for (int k=0;k<;k++){
                
            }
        }
    }
}