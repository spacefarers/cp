// created on 6/21/21 by spacefarers
// problem: Problem 1. Maze Tac Toe

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

#define ll long long
#define f first
#define s second

using namespace std;

string board[30][30];
bool vis[30][30];
int n;
set<pair<int,int>> paths[30][30];
pair<int,int> dirs[4]={{1,0},{-1,0},{0,-1},{0,1}};
char characters[3]={'M','O','.'};

bool check_valid(int x,int y){
    return !(x<0||y<0||x>=n||y>=n||vis[x][y]||board[x][y]=="###");
}

void build_graph(int x,int y,pair<int,int> source){
    if (!check_valid(x,y)) return;
    vis[x][y]=true;
    if (board[x][y][0]=='M'||board[x][y][0]=='O') source={x,y};
    for (auto i:dirs){
        int tx=x+i.f,ty=y+i.s;
        if (!check_valid(tx,ty)) continue;
        if (board[tx][ty][0]=='M'||board[tx][ty][0]=='O')
            paths[source.f][source.s].insert({tx,ty});
        build_graph(tx,ty,source);
    }
    vis[x][y]=false;
}

bool check_pos(const vector<string> &b){
    string diag1,diag2;
    for (int i=0;i<3;i++){
        diag1+=b[i][i];
        diag2+=b[i][2-i];
        string vert;
        for (int j=0;j<3;j++){
            vert+=b[j][i];
        }
        if (vert=="MOO"||vert=="OOM"||b[i]=="MOO"||b[i]=="OOM") return true;
    }
    if (diag1=="MOO"||diag2=="MOO"||diag1=="OOM"||diag2=="OOM") return true;
    return false;
}

vector<vector<string>> permutations;
vector<string> c_p;

void gen_all(int x,int y){
    if (x==3){
        if (check_pos(c_p)) permutations.push_back(c_p);
        return;
    }
    int ty=y,tx=x;
    ty++;
    if (ty==3) ty=0,tx++;
    for (auto i:characters){
        c_p[x][y]=i;
        gen_all(tx,ty);
        c_p[x][y]='.';
    }
}

map<string,vector<pair<int,int>>> mp;
map<string,bool> items;
string special;

void solve(pair<int,int> x){
    if (vis[x.f][x.s]||board[x.f][x.s]==special) return;
    vis[x.f][x.s]=true;
    for (auto i:paths[x.f][x.s]){
        if (items.find(board[i.f][i.s])!=items.end()){
            items[board[i.f][i.s]]=false;
            solve(i);
        }
    }
//    for (auto i:items){
//        if (!i.s) continue;
//        for (auto j:mp[i.f]){
//            if (paths[x.f][x.s].find(j)!=paths[x.f][x.s].end()){
//                i.s=false;
//            }
//            solve(j);
//        }
//    }
}

int main(){
    c_p={"...","...","..."};
    vector<string> test;
    test={"M.M",".O.","O.M"};
    check_pos(test);
    cin>>n;
    pair<int,int> st;
    for (int i=0;i<n;i++){
        string x;
        cin>>x;
        for (int j=0;j<n;j++){
            board[i][j]=x.substr(j*3,3);
            if (board[i][j]=="BBB") st={i,j};
            if (board[i][j][0]=='M'||board[i][j][0]=='O') mp[board[i][j]].push_back({i,j});
        }
    }
    gen_all(0,0);
    build_graph(st.f,st.s,st);
    int ans=0;
    for (auto i:permutations){
        if (i[0]=="M.M"&&i[1]==".O."&&i[2]=="OOM"){
            cout<<"ha"<<endl;
        }
        items.clear();
        pair<int,int> crit={-1,-1};
        for (int j=0;j<3;j++){
            for (int k=0;k<3;k++){
                if (i[j][k]!='.'){
                    items[i[j][k]+to_string(j+1)+to_string(k+1)]=true;
                    auto bp=i[j][k];
                    i[j][k]='.';
                    if (!check_pos(i)){
                        if (crit.f==-1) crit={j,k};
                        else crit={-2,-2};
                    }
                    i[j][k]=bp;
                }
            }
        }
        memset(vis,false,sizeof vis);
        special="";
        if (crit.f!=-2){
            int j=crit.f,k=crit.s;
            special=i[j][k]+to_string(j+1)+to_string(k+1);
        }
        solve(st);
        for (const auto &j:items){
            if (j.s) goto cont;
        }
        ans++;
        cont:;
    }
    cout<<ans<<endl;
}