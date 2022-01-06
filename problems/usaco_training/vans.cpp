/*
ID: michael419
LANG: C++14
TASK: vans
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

#define f first
#define s second

bool board[4][1005];
int n,ans=0;
pair<int,int> dirs[4]={{0,1},{1,0},{0,-1},{-1,0}};

bool isValid(pair<int,int> pos,pair<int,int> dir){
	pos.f+=dir.f;
	pos.s+=dir.s;
	return pos.f>=0&&pos.s>=0&&pos.f<4&&pos.s<n&&!board[pos.f][pos.s];
}

void dfs(pair<int,int> pos,int dep){
	if (dep==4*n-1){
//		if (ans%100==0) cout<<ans<<endl;
		if (pos==make_pair(0,1)||pos==make_pair(1,0)) ans++;
		return;
	}
	if (board[0][1]&&board[1][0]) return;
	board[pos.f][pos.s]=true;
	for (int i=0;i<4;i++){
		auto dir=dirs[i];
		pair<int,int> new_pos={pos.f+dir.f,pos.s+dir.s};
		if (!isValid(pos,dir)) continue;
		auto last_dir=dirs[(i+3)%4];
		auto next_dir=dirs[(i+1)%4];
		if (!isValid(new_pos,dir)&&isValid(new_pos,last_dir)&&isValid(new_pos,next_dir)) continue;
		dfs(new_pos,dep+1);
	}
	board[pos.f][pos.s]=false;
}

int main(){
	setIO("vans");
	cin>>n;
	dfs({0,0},0);
	cout<<ans<<endl;
}