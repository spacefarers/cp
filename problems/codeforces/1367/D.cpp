// created on 2021/7/6 by spacefarers
// problem: D. Task On The Board

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

bool vis[55];

int main(){
    int t;
    cin>>t;
    while (t--){
        string x,ans;
        int n;
        cin>>x>>n;
        sort(x.begin(),x.end());
        ans=x.substr(0,n);
        vector<int> target(n),nums;
        for (int i=0;i<n;i++){
            cin>>target[i];
        }
        memset(vis,false,sizeof vis);
        bool ok=true;
        while (ok){
            ok=false;
            vector<int> lists;
            for (int i=0;i<n;i++){
                if (target[i]==0){
                    ok=true;
                    lists.push_back(i);
                }
            }
            int c=0;
            char previous;
            while (c<lists.size()){
                previous=x.back();
                c=0;
                while (!x.empty()&&x.back()==previous){
                    x.pop_back();
                    c++;
                }
            }
            for (auto i:lists){
                ans[i]=previous;
                target[i]=-1;
                for (int j=0;j<n;j++){
                    target[j]-=abs(i-j);
                }
            }
        }
        cout<<ans<<endl;
    }
}