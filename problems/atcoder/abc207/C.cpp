// created on 2021/6/26 by spacefarers
// problem: C - Many Segments

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<pair<double,double>> ranges;
    for (int i=0;i<n;i++){
        double a,b,c;
        cin>>a>>b>>c;
        if (a==2||a==4) c-=0.1;
        if (a==3||a==4) b+=0.1;
        ranges.emplace_back(b,c);
    }
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (ranges[i].f<=ranges[j].f&&ranges[i].s>=ranges[j].f||ranges[i].f>=ranges[j].f&&ranges[i].f<=ranges[j].s) ans++;
        }
    }
    cout<<ans<<endl;
}

//3
//1 1 2 [1,2]
//2 2 3 [2,3)
//3 2 4 (2,4]