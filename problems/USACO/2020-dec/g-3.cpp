// created on 2021/6/27 by spacefarers
// problem: Problem 3. Square Pasture

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> cows;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        cows.emplace_back(a,b);
    }
    sort(cows.begin(),cows.end());
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int dx=cows[j].f-cows[i].f,dy=abs(cows[i].s-cows[j].s);
            if (dy>dx){
                int left=-1e9,right=1e9;
                for (int k=0;k<n;k++){
                    if (cows[k].f>left&&cows[k].f<cows[i].f) left=cows[k].f;
                    if (cows[k].f<right&&cows[k].f>cows[j].f) right=cows[k].f;
                }
                if (right-left>dy) ans++;
            } else {
                int top=1e9,bot=-1e9;
                int top_level=max(cows[i].s,cows[j].s),low_level=min(cows[i].s,cows[j].s);
                for (int k=0;k<n;k++){
                    if (cows[k].s>bot&&cows[k].s<low_level) bot=cows[k].s;
                    if (cows[k].s<top&&cows[k].s>top_level) top=cows[k].s;
                }
                if (top-bot>dx) ans++;
            }
        }
    }
    cout<<ans+n+1<<endl;
}