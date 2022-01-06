// created on 2021/6/29 by spacefarers
// problem: DP: Elevator Rides

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

pair<int,int> elevators[1<<20];

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> people;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        people.push_back(a);
    }
    elevators[0]={1,0};
    for (int i=1;i<(1<<n);i++){
        elevators[i]={n+1,0};
        for (int j=0;j<n;j++){
            if (i&(1<<j)){
                auto last_res=elevators[i^(1<<j)];
                if (last_res.s+people[j]<=x){
                    last_res.s+=people[j];
                } else {
                    last_res.f++;
                    last_res.s=people[j];
                }
                elevators[i]=min(elevators[i],last_res);
            }
        }
    }
    cout<<elevators[(1<<(n))-1].f<<endl;
}