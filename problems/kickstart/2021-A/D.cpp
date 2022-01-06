#include <iostream>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

#define ll long long
#define ppi pair<int, pair<int, int>>

int board[505][505], costs[505][505], row_count[505], col_count[505];
bool been_to[505][505];
int ans=0;
int n;

void visit(ppi u){
	if (been_to[u.second.first][u.second.second]) return;
	been_to[u.second.first][u.second.second]=true;
	if (row_count[u.second.first]>1&&col_count[u.second.second]>1){
		ans+=u.first;
	}
	row_count[u.second.first]--,col_count[u.second.second]--;
	if (row_count[u.second.first]==1){
		for (int i=0;i<n;i++){
			visit({costs[u.second.first][i], {u.second.first, i}});
		}
	}
	if (col_count[u.second.second]==1){
		for (int i=0;i<n;i++){
			visit({costs[i][u.second.second], {i,u.second.second}});
		}
	}
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		memset(been_to, true, sizeof been_to);
		memset(col_count, 0, sizeof col_count);
		memset(row_count, 0, sizeof row_count);
		ans=0;
		cin>>n;
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				cin>>board[j][k];
			}
		}
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				cin>>costs[j][k];
			}
		}
		int no_use;
		for (int j=0;j<n;j++){
			cin>>no_use;
		}
		for (int j=0;j<n;j++){
			cin>>no_use;
		}
		priority_queue<ppi, vector<ppi>, greater<>> q;
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				if (board[j][k]==-1){
					q.push({costs[j][k], {j, k}});
					row_count[j]++;
					col_count[k]++;
					been_to[j][k]=false;
				}
			}
		}
		for (int j=0;j<n;j++){
			if (row_count[j]!=1) continue;
			for (int k=0;k<n;k++){
				visit({costs[j][k], {j, k}});
			}
		}
		for (int j=0;j<n;j++){
			if (col_count[j]!=1) continue;
			for (int k=0;k<n;k++){
				visit({costs[k][j], {k, j}});
			}
		}
		while (!q.empty()){
			auto u=q.top();
			q.pop();
			visit(u);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}