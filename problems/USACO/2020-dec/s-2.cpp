#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define f first
#define s second

vector<pair<int, int>> points;
ll ans=0;

int n;

int main(){
    cin>>n;
    int minx=0x7fffffff, miny=0x7fffffff, maxx=0, maxy=0;
    for (int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        points.emplace_back(x, y);
    }
    sort(points.begin(), points.end());
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int c=0;
            for (int k=i;k<=j;k++){
                if ((points[k].s>points[i].s&&points[k].s<points[j].s)||(points[k].s<points[i].s&&points[k].s>points[j].s)) c++;
            }
            ans+=(pow(2, c)-1)*(n-c);
        }
    }
    ans/=-2;
    ans+=pow(2, n);
    cout<<ans<<endl;
}