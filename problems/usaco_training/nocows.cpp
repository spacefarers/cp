/*
ID: michael419
LANG: C++
TASK: nocows
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;


void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int table[105][205];
int smalltrees[105][205], mod=9901;

int main(){
    setIO("nocows");
    int n, k, c;
    cin>>n>>k;
    table[1][1]=1;
    for (int i=2;i<=k;i++){
        for (int j=1;j<=n;j+=2){
            for (int l=1;l<=j-1-l;l+=2){
                if (l!=j-1-l) c=2; else c=1;
                table[i][j]+=c*(smalltrees[i-2][l]*table[i-1][j-1-l]+
                        table[i-1][l]*smalltrees[i-2][j-1-l]+
                        table[i-1][l]*table[i-1][j-1-l]);
                table[i][j]%=mod;
            }
        }
        for (int j=0;j<=n;j++){
            smalltrees[i-1][j]+=table[i-1][j]+smalltrees[i-2][j];
            smalltrees[i-1][j]%=mod;
        }
    }
    cout<<table[k][n]<<endl;
}