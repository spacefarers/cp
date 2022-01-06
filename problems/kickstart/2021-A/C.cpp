#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[305][305];
pair<int,int> dirs[4]={{1,0},{-1,0},{0,1},{0,-1}};
int R, C;

bool valid(int y, int x){
	return y>=0&&x>=0&&y<R&&x<C;
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		memset(board, 0, sizeof board);
		cin>>R>>C;
		priority_queue<pair<int, pair<int, int>>> q;
		for (int j=0;j<R;j++){
			for (int k=0;k<C;k++){
				int a;
				cin>>a;
				q.push({a, {j, k}});
				board[j][k]=a;
			}
		}
		long long ans=0;
		while (!q.empty()){
			auto u=q.top();
			q.pop();
			if (u.first<board[u.second.first][u.second.second]) continue;
			for (auto &j:dirs){
				int new_y=u.second.first+j.first;
				int new_x=u.second.second+j.second;
				if (!valid(new_y, new_x)) continue;
				if (board[new_y][new_x]+1<u.first){
					ans+=u.first-(board[new_y][new_x]+1);
					board[new_y][new_x]=u.first-1;
					q.push({board[new_y][new_x], {new_y, new_x}});
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}