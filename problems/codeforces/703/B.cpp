#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<pair<int, int>> houses;
        for (int i=0;i<n;i++){
            int a, b;
            cin>>a>>b;
            houses.emplace_back(a, b);
        }
        if (n%2){
            cout<<1<<endl;
            continue;
        }
        long long horiz, vert;
        sort(houses.begin(), houses.end());
        horiz=houses[n/2].f-houses[n/2-1].f+1;
        sort(houses.begin(), houses.end(), [](pair<int, int> a, pair<int, int> b){return a.second<b.second;});
        vert=houses[n/2].s-houses[n/2-1].s+1;
        cout<<horiz*vert<<endl;
    }
}