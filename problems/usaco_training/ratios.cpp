/*
ID: michael419
LANG: C++
TASK: ratios
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

int main(){
    setIO("ratios");
    int target[3];
    vector<vector<int>> mixtures(3);
    cin>>target[0]>>target[1]>>target[2];
    for (int i=0;i<3;i++){
        mixtures[i].reserve(3);
        cin>>mixtures[i][0]>>mixtures[i][1]>>mixtures[i][2];
    }
    for (int i=1;i<=100;i++){
        for (int j=0;j<=100;j++){
            for (int k=0;k<=100;k++){
                int aim=target[0]*i-mixtures[0][0]*j-mixtures[1][0]*k;
                int aim2=target[1]*i-mixtures[0][1]*j-mixtures[1][1]*k;
                int aim3=target[2]*i-mixtures[0][2]*j-mixtures[1][2]*k;
                if (aim<0||aim2<0||aim3<0||(aim!=0&&(mixtures[2][0]==0||aim%mixtures[2][0]))) continue;
                int ratio=0;
                if (mixtures[2][0]!=0&&aim!=0) ratio=aim/mixtures[2][0];
                else if (mixtures[2][1]!=0&&aim2!=0) ratio=aim2/mixtures[2][1];
                else if (mixtures[2][2]!=0&&aim3!=0) ratio=aim3/mixtures[2][2];
                if (mixtures[2][1]*ratio==aim2&&mixtures[2][2]*ratio==aim3){
                    cout<<j<<" "<<k<<" "<<ratio<<" "<<i<<endl;
                    exit(0);
                }
            }
        }
    }
    cout<<"NONE"<<endl;
}