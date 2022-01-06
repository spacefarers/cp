/*
ID: michael419
LANG: C++
TASK: comehome
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

int dist[100];
bool has_cow[100];
vector<pair<int, int>> paths[100];

int main(){
    setIO("comehome");
    int n;
    cin>>n;
    memset(dist, 0x3f, sizeof dist);
    for (int i=0;i<n;i++){
        char A, B;
        int c;
        cin>>A>>B>>c;
        int a=A-'A', b=B-'A';
        if (isupper(A)) has_cow[a]=true;
        if (isupper(B)) has_cow[b]=true;
        paths[a].emplace_back(b, c);
        paths[b].emplace_back(a, c);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 'Z'-'A'});
    dist['Z'-'A']=0;
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        if (dist[u.s]<u.f) continue;
        for (auto &i:paths[u.s]){
            if (dist[i.f]>dist[u.s]+i.s){
                dist[i.f]=dist[u.s]+i.s;
                q.push({dist[i.f], i.f});
            }
        }
    }
    int ans=0x7fffffff;
    char ans_pasture;
    for (int i=0;i<'Z'-'A';i++){
        if (has_cow[i]&&dist[i]<ans){
            ans=dist[i];
            ans_pasture=(char)(i+'A');
        }
    }
    cout<<ans_pasture<<" "<<ans<<endl;
}