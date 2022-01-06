// created on 2021/7/30 by spacefarers
// problem: B. Two Tables

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        int W,H,x1,y1,x2,y2,w,h;
        cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
        int ans=1e9;
        if (w<=W-x2+x1){
            ans=min(ans,min(w-x1,x2-W+w));
        }
        if (h<=H-y2+y1){
            ans=min(ans,min(h-y1,y2-H+h));
        }
        ans=max(ans,0);
        if (ans==1e9) ans=-1;
        cout<<ans<<endl;
    }
}