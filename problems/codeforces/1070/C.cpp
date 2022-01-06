// created on 2021/7/9 by spacefarers
// problem: C. Cloud Computing
// todo: Finish this problem.

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<pair<int,int>> timeline[1000005];

int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<pair<pair<int,int>,pair<int,int>>> tariffs;
    for (int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        tariffs.push_back({{d,c},{a,b}});
    }
    sort(tariffs.begin(),tariffs.end());

}