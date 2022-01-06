/*
ID: michael419
LANG: C++
TASK: starry
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}


string board[505];
set<pair<int, int>> c;
pair<int, int> dirs[8]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
bool vis[505][505];
map<set<pair<int, int>>, char> mp;
char ans[505][505];

int W, H;

void dfs(int x, int y){
	if (x<0||y<0||x>=H||y>=W||vis[x][y]||board[x][y]=='0') return;
	vis[x][y]=true;
	c.insert({x, y});
	for (auto &i:dirs){
		dfs(x+i.first, y+i.second);
	}
}

set<pair<int, int>> rotate(const set<pair<int, int>> &S){
	set<pair<int, int>> new_set;
	int maxx=0;
	for (auto &i:S){
		maxx=max(maxx, i.f);
	}
	for (auto &i:S){
		new_set.insert({i.s, maxx-i.f});
	}
	return new_set;
}
set<pair<int, int>> reflect(const set<pair<int, int>> &S){
	set<pair<int, int>> new_set;
	int maxy=0;
	for (auto &i:S){
		maxy=max(maxy, i.s);
	}
	for (auto &i:S){
		new_set.insert({i.f, maxy-i.s});
	}
	return new_set;
}

int main(){
	setIO("starry");
	cin>>W>>H;
	for (int i=0;i<H;i++){
		cin>>board[i];
	}
	int c_letter=0;
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (!vis[i][j]&&board[i][j]=='1'){
				dfs(i, j);
				auto cp=(*c.begin());
				set<pair<int, int>> new_s;
				for (auto &k:c){
					new_s.insert({k.f-cp.f, k.s-cp.s});
				}
				auto reflected_s=reflect(new_s);
				char c_ans='X';
				for (int k=0;k<5;k++){
					if (mp[new_s]!=char()){
						c_ans=mp[new_s];
						break;
					}
					if (mp[reflected_s]!=char()){
						c_ans=mp[reflected_s];
						break;
					}
					new_s=rotate(new_s);
					reflected_s=rotate(reflected_s);
				}
				if (c_ans=='X'){
					c_ans=(char)(c_letter+'a');
					c_letter++;
					mp[new_s]=c_ans;
				}
				for (auto &k:c){
					ans[k.f][k.s]=c_ans;
				}
				c.clear();
			}
		}
	}
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (ans[i][j]) cout<<ans[i][j];
			else cout<<0;
		}
		cout<<endl;
	}
}