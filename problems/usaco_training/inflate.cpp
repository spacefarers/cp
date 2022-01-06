/*
ID: michael419
LANG: C++
TASK: inflate
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>

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

int max_points[10005];

int main(){
    setIO("inflate");
    int m, n;
    cin>>m>>n;
    vector<pair<int, int>> problems;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        problems.emplace_back(a, b);
    }
    for (int i=0;i<=m;i++){
        for (auto &j:problems){
            if (i-j.s>=0) max_points[i]=max(max_points[i-j.s]+j.f, max_points[i]);
        }
    }
    cout<<max_points[m]<<endl;
}