// created on 2021/7/30 by spacefarers
// problem: E. Boring Segments

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

vector<pair<pair<int,int>,int>> segments;
int n,m;

int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int a,b,v;
        cin>>a>>b>>v;
        segments.push_back({{a,v},b});
    }
    sort(segments.begin(),segments.end());
    for (auto i:segments){
        if (i.f.f!=1) break;
        int cIndex=i.s;
        while (cIndex<)
    }
}