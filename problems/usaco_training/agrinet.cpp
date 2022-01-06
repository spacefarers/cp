/*
ID: michael419
LANG: C++
TASK: agrinet
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

int father[105];

int find(int x){
    if (father[x]!=x) father[x]=find(father[x]);
    return father[x];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    father[c]=d;
}

int main(){
    setIO("agrinet");
    int n;
    cin>>n;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    for (int i=0;i<n;i++){
        father[i]=i;
        for (int j=0;j<n;j++){
            int a;
            cin>>a;
            if (i==j) continue;
            q.push({a, {i, j}});
        }
    }
    int mst=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (find(u.s.f)!=find(u.s.s)) {
            unionn(u.s.f, u.s.s);
            mst+=u.f;
        }
    }
    cout<<mst<<endl;
}