/*
ID: michael419
LANG: C++
TASK: cowtour
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

int father[200];
double dist[200][200];
double max_dists[200];
vector<int> children[200];

int find(int x){
    if (x!=father[x]) father[x]=find(father[x]);
    return father[x];
}

void unionn(int a, int b){
    int c=find(a);
    int d=find(b);
    father[c]=d;
    vector<int> temp=children[c];
    children[c].clear();
    children[d].insert(children[d].end(), temp.begin(), temp.end());
}

int main(){
    setIO("cowtour");
    int n;
    cin>>n;
    memset(dist, 0x7f, sizeof dist);
    vector<pair<int, int>> pos;
    for (int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        pos.emplace_back(a, b);
        father[i]=i;
        children[i].push_back(i);
        dist[i][i]=0;
    }
    for (int i=0;i<n;i++){
        string a;
        cin>>a;
        for (int j=0;j<n;j++){
            if (a[j]=='1') {
                int x=pos[i].f-pos[j].f;
                int y=pos[i].s-pos[j].s;
                double distance=sqrt(x*x+y*y);
                dist[i][j]=distance;
                dist[j][i]=distance;
                unionn(i, j);
            }
        }
    }
    vector<vector<int>> groups;
    for (int i=0;i<n;i++){
        if (!children[i].empty()){
            groups.push_back(children[i]);
        }
    }
    for (auto &i:groups){
        for (auto &j:i){
            for (auto &k:i){
                for (auto &l:i){
                    if (dist[j][k]>dist[j][l]+dist[l][k]){
                        dist[j][k]=dist[j][l]+dist[l][k];
                        dist[k][j]=dist[j][l]+dist[l][k];
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        double max_dist=0;
        for (int j=0;j<n;j++){
            if (dist[i][j]>10000000) continue;
            max_dist=max(max_dist, dist[i][j]);
        }
        max_dists[i]=max_dist;
    }
    double min_dist=0x7fffffff;
    for (auto &i:groups){
        for (auto &j:groups){
            if (i==j) continue;
            double min_pos_dis=0;
            for (auto &k:i){
                min_pos_dis=max(min_pos_dis, max_dists[k]);
            }
            for (auto &k:j){
                min_pos_dis=max(min_pos_dis, max_dists[k]);
            }
            for (auto &k:i){
                for (auto &l:j){
                    ll x=pos[k].f-pos[l].f;
                    ll y=pos[k].s-pos[l].s;
                    double distance=sqrt(x*x+y*y);
                    min_dist=min(min_dist, distance+max_dists[k]+max_dists[l]);
                    if (min_dist<min_pos_dis) min_dist=min_pos_dis;
                }
            }
        }
    }
    printf("%.6f\n", min_dist);
}