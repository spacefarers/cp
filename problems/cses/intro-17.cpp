#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

char board[8][8];
ll ans=0;
vector<int> queens;

void dfs(){
    if (queens.size()==8){
        ans++;
        return;
    }
    for (int i=0;i<8;i++){
        bool ok=true;
        if (board[queens.size()][i]=='*') continue;
        for (int j=0;j<queens.size();j++){
            if (i==queens[j]||abs(i-queens[j])==abs(j-(int)queens.size())) {
                ok=false;
                break;
            }
        }
        if (ok) {
            queens.push_back(i);
            dfs();
            queens.pop_back();
        }
    }
}

int main(){
    for (auto & i : board){
        string a;
        cin>>a;
        for (int j=0;j<8;j++){
            i[j]=a[j];
        }
    }
    dfs();
    cout<<ans<<endl;
}