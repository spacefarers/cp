// created on 2021/7/11 by spacefarers
// problem: B. AquaMoon and Stolen String

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int c[100005][26];

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(c,0,sizeof c);
        int n,m;
        cin>>n>>m;
        for (int i=0;i<n;i++){
            string x;
            cin>>x;
            for (int j=0;j<m;j++){
                c[j][x[j]-'a']++;
            }
        }
        for (int i=0;i<n-1;i++){
            string x;
            cin>>x;
            for (int j=0;j<m;j++){
                c[j][x[j]-'a']--;
            }
        }
        string ans;
        for (int i=0;i<m;i++){
            for (int j=0;j<26;j++){
                if (c[i][j]!=0) ans+=char(j+'a');
            }
        }
        cout<<ans<<endl;
    }
}