// created on 6/20/21 by spacefarers
// problem: D. Cleaning
// key is to compute from both directions

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

ll front[200005],rev[200005],nums[200005];

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        memset(front,0,sizeof front);
        memset(rev,0,sizeof rev);
        for (int i=1;i<=n;i++){
            cin>>nums[i];
        }
        bool skip_check=true;
        for (int i=1;i<=n;i++){
            front[i]=nums[i]-front[i-1];
            if (front[i]<0) front[i]=-1e17;
        }
        for (int i=n;i>0;i--){
            rev[i]=nums[i]-rev[i+1];
            if (rev[i]<0) rev[i]=1e17;
        }
        if (front[n]==0) cout<<"YES"<<endl;
        else{
            for (int i=1;i<n;i++){
                if (rev[i+2]-nums[i]+nums[i+1]-front[i-1]==0&&nums[i+1]-front[i-1]>=0){
                    cout<<"YES"<<endl;
                    goto cont;
                }
            }
            cout<<"NO"<<endl;
            cont:;
        }
    }
}