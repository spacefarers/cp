#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nums[105][105];
pair<int,int> mapping[105][105];

pair<int,int> find(pair<int,int> pos,pair<int,int> new_pos={-1,-1}){
    if (new_pos.first==-1) new_pos=pos;
    if (pos==mapping[new_pos.first][new_pos.second]) return new_pos;
    return find(pos,mapping[new_pos.first][new_pos.second]);
}

int main(){
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,pair<int,int>>> all_num;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                mapping[i][j]={i,j};
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cin>>nums[i][j];
                all_num.push_back({nums[i][j],{i,j}});
            }
        }
        sort(all_num.begin(),all_num.end());
        for (int i=0;i<m;i++){
            int x=all_num[i].second.first,y=all_num[i].second.second;
            auto new_maps=find({x,y});
            x=new_maps.first,y=new_maps.second;
            swap(nums[x][y],nums[x][i]);
            swap(mapping[x][y],mapping[x][i]);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                cout<<nums[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}