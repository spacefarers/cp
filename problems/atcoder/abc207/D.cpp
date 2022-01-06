// created on 2021/6/26 by spacefarers
// problem: D - Congruence Points

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

#define ll long long
#define f first
#define s second

#define PI 3.14159265

using namespace std;

vector<pair<int,int>> S[105],U[105];

int main(){
    int n;
    cin>>n;
    for (int u=0;u<2;u++){
        vector<pair<int,int>> pos;
        for (int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            pos.emplace_back(a,b);
        }
        for (int i=0;i<n;i++){
            vector<pair<double,int>> order;
            for (int j=0;j<n;j++){
                if (i==j) continue;
                int dx=pos[i].f-pos[j].f;
                int dy=pos[i].s-pos[j].s;
                double angle=atan2(dy,dx)*180/PI;
                order.emplace_back(angle,dx*dx+dy*dy);
            }
            sort(order.begin(),order.end());
            pair<pair<int,double>,int> max={{-1e9,-1e9},-1};
            for (int j=0;j<n-1;j++){
                int next_angle=(int)round((order[(j+1)%(n-1)].f-order[(j)%(n-1)].f)*100);
                if (next_angle<0) next_angle+=36000;
                if (order[j].s>max.f.f||(order[j].s==max.f.f&&next_angle>max.f.s)) max={{order[j].s,next_angle},j};
            }
            for (int j=0;j<n-1;j++){
                int next_angle=(int)round((order[(max.s+j+1)%(n-1)].f-order[(max.s+j)%(n-1)].f)*100);
                if (next_angle<0) next_angle+=36000;
                U[i].emplace_back(order[(max.s+j)%(n-1)].s,next_angle);
            }
        }
        if (u==0) swap(U,S);
        else {
            for (int i=0;i<n;i++){
                bool ok=false;
                for (int j=0;j<n;j++){
                    if (S[i]==U[j]){
                        U[j].clear();
                        ok=true;
                        break;
                    }
                }
                if (!ok) goto cont;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
    cont:;
    cout<<"No"<<endl;
}