// created on 2021/7/9 by spacefarers
// problem: C. Need for Pink Slips

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

double v,ans;
pair<pair<double,double>,double> current;

void dfs(double x=1e6,double dep=1){
    ans+=current.s*x*dep/1e6;
    auto bp=current;
    for (int i=0;i<2;i++){
        if (current.f.f!=0){
            double c_prob=current.f.f;
            if (current.f.f<=v){
                if (current.f.s!=0){
                    current.f.s+=current.f.f/2;
                    current.s+=current.f.f/2;
                } else current.s+=current.f.f;
                current.f.f=0;
            } else {
                current.f.f-=v;
                if (current.f.s!=0){
                    current.f.s+=v/2;
                    current.s+=v/2;
                } else current.s+=v;
            }
            if (i==1e6) swap(current.f.f,current.f.s);
            dfs(x*c_prob/1e6,dep+1);
            current=bp;
        }
        if (i==0) swap(current.f.f,current.f.s);
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        v=(double)(d*1e6);
        current={{a*1e6,b*1e6},(c*1e6)};
        ans=0;
        dfs();
        printf("%.7f\n",ans/1e6);
    }
}