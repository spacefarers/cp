#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int t;
    cin>>t;
    while (t--){
        int n, m;
        cin>>n>>m;
        vector<int> ones, twos;
        vector<pair<int, int>> apps(n);
        for (int i=0;i<n;++i) cin>>apps[i].first;
        for (int i=0;i<n;++i) cin>>apps[i].second;
        for (auto &i:apps){
            if (i.second==1) ones.push_back(i.first);
            else if (i.second==2) twos.push_back(i.first);
        }
        sort(ones.begin(), ones.end(), greater<>());
        sort(twos.begin(), twos.end(), greater<>());
        int min_points=1e9,c_points=0,freed_space=0,one_pointer=0,two_pointer=0;
        while (freed_space<m&&one_pointer<ones.size()){
            freed_space+=ones[one_pointer++];
            c_points++;
        }
        while (freed_space<m&&two_pointer<twos.size()){
            freed_space+=twos[two_pointer++];
            c_points+=2;
        }
        if (freed_space<m) {
            cout<<-1<<endl;
            continue;
        }
        min_points=min(min_points,c_points);
        while (one_pointer>0){
            freed_space-=ones[--one_pointer];
            c_points--;
            while (freed_space<m&&two_pointer<twos.size()){
                freed_space+=twos[two_pointer++];
                c_points+=2;
            }
            if (freed_space<m) break;
            min_points=min(min_points,c_points);
        }
        cout<<min_points<<endl;
    }
}