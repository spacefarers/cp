/*
ID: michael419
LANG: C++
TASK: snail
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

vector<vector<bool>> board;
bool has_block[150][150];
pair<int, int> dirs[4]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int N, B, ans=0;

bool valid(int new_x, int new_y){
	return !(new_x<0||new_y<0||new_x>=N||new_y>=N||board[new_x][new_y]||has_block[new_x][new_y]);
}

void dfs(int x, int y, int d, int dep){
	if (!valid(x, y)) return;
	board[x][y]=true;
	ans=max(ans, dep);
	int new_x=x+dirs[d].f, new_y=y+dirs[d].s;
	if (valid(new_x, new_y)) dfs(new_x, new_y, d, dep+1);
	else if (new_x<0||new_y<0||new_x>=N||new_y>=N||has_block[new_x][new_y]){
		for (int i=0;i<4;i++){
			dfs(x+dirs[i].f, y+dirs[i].s, i, dep+1);
		}
	}
	board[x][y]=false;
}

int main(){
	setIO("snail");
	cin>>N>>B;
	for (int i=0;i<N;i++){
		vector<bool> vec(N);
		board.push_back(vec);
	}
	for (int i=0;i<B;i++){
		string a;
		cin>>a;
		has_block[a[0]-'A'][stoi(a.substr(1, a.size()-1))-1]=true;
	}
	dfs(0, 0, 0, 1);
	dfs(0, 0, 4, 1);
	cout<<ans<<endl;
}