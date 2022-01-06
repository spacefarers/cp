// created on 2021/7/17 by spacefarers
// problem: B. Putting Plates

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

string ans[25];

int main(){
    int t;
    cin>>t;
    while (t--){
        int h,w;
        cin>>h>>w;
        for (int i=0;i<h;i++){
            ans[i]=string(w,'0');
        }
        ans[0][0]='1';
        ans[0][w-1]='1';
        ans[h-1][w-1]='1';
        ans[h-1][0]='1';
        for (int i=0;i<w;i++){
            if (ans[0][i-1]=='1'||ans[0][i+1]=='1') continue;
            ans[h-1][i]='1';
            ans[0][i]='1';
        }
        for (int i=0;i<h;i++){
            if (ans[i-1][0]=='1'||ans[i+1][0]=='1') continue;
            ans[i][0]='1';
            ans[i][w-1]='1';
        }
        for (int i=0;i<h;i++){
            cout<<ans[i]<<endl;
        }
        cout<<endl;
    }
}