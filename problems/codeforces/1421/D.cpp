// created on 2021/7/1 by spacefarers
// problem: D. Hexagons

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define ll long long
#define f first
#define s second

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        ll x,y;
        cin>>x>>y;
        swap(x,y);
        ll ru,r,d,ld,l,u;
        cin>>ru>>r>>d>>ld>>l>>u;
        ru=min(ru,r+u);
        ld=min(ld,l+d);
        r=min(r,ru+d);
        l=min(l,ld+u);
        u=min(u,ru+l);
        d=min(d,ld+r);
        ll ans;
        if (x>=0&&y>=0){
            // quadrant 1
            ll rus=min(x,y);
            ans=rus*ru+(x-rus)*r+(y-rus)*u;
        } else if (x<=0&&y<=0){
            // quadrant 3
            ll lds=-max(x,y);
            ans=lds*ld-(x+lds)*l-(y+lds)*d;
        } else if (x>=0&&y<=0){
            // quadrant 4
            ans=r*x-d*y;
        } else {
            // quadrant 2
            ans=u*y-l*x;
        }
        cout<<ans<<endl;
    }
}