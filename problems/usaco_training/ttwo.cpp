/*
ID: michael419
LANG: C++
TASK: ttwo
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}

string board[15];

bool invalid(pair<int, int> x){
    return x.first<0||x.second<0||x.first>=10||x.second>=10||board[x.first][x.second]=='*';
}

int main(){
    setIO("ttwo");
    pair<int, int> cow_loc, john_loc;
    for (int i=0;i<10;i++){
        cin>>board[i];
        for (int j=0;j<10;j++){
            if (board[i][j]=='C'){
                cow_loc={i, j};
            } else if (board[i][j]=='F'){
                john_loc={i, j};
            }
        }
    }
    pair<int, int> dir[4]={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int dir_john=0, dir_cow=0, ans=0;
    for (int i=0;i<100000;i++){
        auto new_cow_loc=cow_loc, new_john_loc=john_loc;
        new_cow_loc.first+=dir[dir_cow].first;
        new_cow_loc.second+=dir[dir_cow].second;
        new_john_loc.first+=dir[dir_john].first;
        new_john_loc.second+=dir[dir_john].second;
        if (invalid(new_cow_loc)) dir_cow=(dir_cow+1)%4;
        else cow_loc=new_cow_loc;
        if (invalid(new_john_loc)) dir_john=(dir_john+1)%4;
        else john_loc=new_john_loc;
        ans++;
        if (cow_loc==john_loc){
            cout<<ans<<endl;
            exit(0);
        }
    }
    cout<<0<<endl;
}