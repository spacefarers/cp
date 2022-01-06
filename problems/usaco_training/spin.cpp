/*
ID: michael419
LANG: C++
TASK: spin
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
    setIO("spin");
    vector<pair<int, vector<pair<int, int>>>> wheels(5);
    for (int i=0;i<5;i++){
        int s, w;
        cin>>s>>w;
        wheels[i].f=s;
        for (int j=0;j<w;j++){
            int a, b;
            cin>>a>>b;
            wheels[i].s.emplace_back(a, (a+b)%360);
        }
    }
    vector<int> pos(5);
    int t=0;
    while (true){
        if (t>1000) break;
        for (int i=0;i<360;i++){
            bool wheels_ok=true;
            for (int u=0;u<5;u++){
                auto j=wheels[u];
                bool wedge_ok=false;
                for (auto &k:j.s){
                    if (((k.f+pos[u])%360>(k.s+pos[u])%360&&(i>=(k.f+pos[u])%360||i<=(k.s+pos[u])%360))||(i>=(k.f+pos[u])%360&&i<=(k.s+pos[u])%360)) wedge_ok=true;
                }
                if (!wedge_ok) wheels_ok=false;
            }
            if (wheels_ok){
                cout<<t<<endl;
                exit(0);
            }
        }
        for (int i=0;i<5;i++){
            pos[i]+=wheels[i].f;
            pos[i]%=360;
        }
        t++;
    }
    cout<<"none"<<endl;
}