/*
ID: michael419
LANG: C++
TASK: range
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

int field[255][255];
int sums[255][255];

int main(){
    setIO("range");
    int N;
    cin>>N;
    for (int i=1;i<=N;i++){
        string a;
        cin>>a;
        for (int j=0;j<N;j++){
            field[i][j+1]=a[j]-'0';
        }
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+field[i][j];
        }
    }
    for (int i=2;i<=N;i++){
        int ans=0;
        for (int j=1;j<=N-i+1;j++){
            for (int k=1;k<=N-i+1;k++){
                if (sums[j+i-1][k+i-1]-sums[j+i-1][k-1]-sums[j-1][k+i-1]+sums[j-1][k-1]==i*i) ans++;
            }
        }
        if (ans==0) break;
        cout<<i<<" "<<ans<<endl;
    }
}