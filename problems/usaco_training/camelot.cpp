/*
ID: michael419
LANG: C++
TASK: camelot
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
}


int R, C, knight_jumps[35][35][35][35];
pair<int, int> dir_knight[8]={{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
pair<int, int> dir_king[8]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

bool valid(pair<int, int> pos){
    return pos.f>=0&&pos.s>=0&&pos.f<R&&pos.s<C;
}
pair<int, int> king_pos;
vector<pair<int, int>> knight_pos;
int vis[35][35];

int king_walk(int i, int j){
    int x=abs(king_pos.f-i), y=abs(king_pos.s-j);
    int ans=min(x, y)+x-min(x, y)+y-min(x, y);
    return ans;
}

int main(){
    setIO("camelot");
    cin>>R>>C;
    char a;
    int b;
    cin>>a>>b;
    king_pos={b-1, a-'A'};
    int c=0;
    while (cin>>a){
        cin>>b;
        knight_pos.emplace_back(b-1, a-'A');
//        if (c++>=1*1-1) break;
    }
    memset(knight_jumps, -1, sizeof knight_jumps);
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            queue<pair<int, int>> q;
            knight_jumps[i][j][i][j]=0;
            q.push({i, j});
            int steps=1;
            while (!q.empty()){
                int sz=q.size();
                while (sz--){
                    auto u=q.front();
                    q.pop();
                    for (auto &k:dir_knight){
                        auto new_pos=u;
                        new_pos.f+=k.f;
                        new_pos.s+=k.s;
                        if (valid(new_pos)&&knight_jumps[i][j][new_pos.f][new_pos.s]==-1){
                            knight_jumps[i][j][new_pos.f][new_pos.s]=steps;
                            q.push(new_pos);
                        }
                    }
                }
                steps++;
            }
        }
    }
    int ans=0x7fffffff;
    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            // no pickup
            int knight_jump=0;
            bool ok=true;
            for (auto &k:knight_pos){
                if (knight_jumps[k.f][k.s][i][j]==-1) {
                    ok=false;
                    break;
                }
                knight_jump+=knight_jumps[k.f][k.s][i][j];
            }
            if (!ok) continue;
            ans=min(ans, knight_jump+king_walk(i, j));

            // pickup
            if (knight_pos.empty()) continue;
            int min_steps=0x7fffffff, king_step=0;
            vector<pair<int, int>> squares;
            while (min_steps>king_step){
                squares.clear();
                squares.push_back(king_pos);
                memset(vis, -1, sizeof vis);
                vis[king_pos.f][king_pos.s]=0;
                for (int k=0;k<king_step;k++){
                    int sz=squares.size();
                    for (int l=0;l<sz;l++){
                        for (auto &m:dir_king){
                            auto new_pos=squares[l];
                            new_pos.f+=m.f;
                            new_pos.s+=m.s;
                            if (valid(new_pos)&&vis[new_pos.f][new_pos.s]==-1){
                                vis[new_pos.f][new_pos.s]=k+1;
                                squares.push_back(new_pos);
                            }
                        }
                    }
                }
                for (auto &k:knight_pos){
                    for (auto &l:squares){
                        if (knight_jumps[k.f][k.s][l.f][l.s]==-1||knight_jumps[l.f][l.s][i][j]==-1) continue;
                        min_steps=min(min_steps, knight_jumps[k.f][k.s][l.f][l.s]-knight_jumps[k.f][k.s][i][j]+knight_jumps[l.f][l.s][i][j]+king_walk(l.f, l.s));
                    }
                }
                king_step++;
            }
            ans=min(ans, knight_jump+min_steps);
        }
    }
    cout<<ans<<endl;
}