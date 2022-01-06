/*
ID: michael419
LANG: C++
TASK: shopping
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

pair<vector<pair<int, int>>, int> discounts[1000];
vector<int> current;
int price[1000], items[1000];
int B, c_price=0, ans=0x7fffffff;
int S;
map<vector<int>, int> dist;
map<int, int> mp;

int main(){
    setIO("shopping");
    cin>>S;
    for (int i=0;i<S;i++){
        int n;
        cin>>n;
        for (int j=0;j<n;j++){
            int a, b;
            cin>>a>>b;
            discounts[i].f.emplace_back(a, b);
        }
        int p;
        cin>>p;
        discounts[i].s=p;
    }
    cin>>B;
    for (int i=0;i<B;i++){
        int c, d, e;
        cin>>c>>d>>e;
        price[i]=e;
        items[i]=c;
        mp[c]=i;
        current.push_back(d);
    }
    dist[current]=1;
    vector<int> target;
    target.reserve(B);
    for (int i=0;i<B;i++){
        target.push_back(0);
    }
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
    q.push({1, current});
    while (!q.empty()){
        auto u=q.top();
        q.pop();
        current=u.s;
        if (current==vector<int>{1, 0, 0, 3}){

        }
        if (dist[u.s]<u.f) continue;
        for (int i=0;i<S;i++){
            auto new_arr=current;
            bool ok=true;
            for (auto &j:discounts[i].f){
                if (mp.find(j.f)==mp.end()){
                    ok=false;
                    break;
                }
                int ind=mp[j.f];
                if (new_arr[ind]-j.s>=0){
                    new_arr[ind]-=j.s;
                } else ok=false;
            }
            if (!ok) continue;
            if (dist[new_arr]>dist[u.s]+discounts[i].s||dist[new_arr]==0){
                dist[new_arr]=dist[u.s]+discounts[i].s;
                q.push({dist[new_arr], new_arr});
            }
        }
        int c_p=dist[u.s];
        for (int i=0;i<B;i++){
            c_p+=price[i]*current[i];
        }
        if (c_p<dist[target]||dist[target]==0){
            dist[target]=c_p;
        }
    }
//    cout<<dist[{1, 0, 0, 3}]<<endl;
    cout<<dist[target]-1<<endl;
}