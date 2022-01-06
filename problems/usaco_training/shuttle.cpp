/*
ID: michael419
LANG: C++14
TASK: shuttle
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("shuttle");
	int N;
	cin>>N;
	vector<int> board(2*N+1), target(2*N+1);
	for (int i=0;i<N;i++){
		board[i]=1;
		target[i]=-1;
	}
	for (int i=N+1;i<2*N+1;i++){
		board[i]=-1;
		target[i]=1;
	}
	queue<vector<int>> q;
	q.push(board);
	map<vector<int>, int> dist;
	map<vector<int>, vector<int>> track;
	dist[board]=1;
	int steps=2;
	while (!q.empty()){
		int sz=q.size();
		while (sz--){
			auto u=q.front();
			q.pop();
			bool ok=true, broken=false, met=true;
			for (int i=1;i<2*N;i++){
				if ((i<N&&u[i-1]==0&&u[i]==1&&u[i+1]==1)||(i>N&&u[i-1]==-1&&u[i]==-1&&u[i+1]==0)){
					ok=false;
					break;
				}
				if (broken&&met&&u[i-1]==-1&&u[i]==-1){
					ok=false;
					break;
				}
				if (u[i]!=-1) broken=true;
				if (u[i]==0) met=false;
			}
			broken=false, met=true;
			for (int i=2*N;i>=1;i--){
				if (broken&&met&&u[i-1]==1&&u[i]==1){
					ok=false;
					break;
				}
				if (u[i]!=1) broken=true;
				if (u[i]==0) met=false;
			}
			if (!ok){
				continue;
			}
			for (int i=0;i<2*N;i++){
				if (i>0&&((u[i-1]==1&&u[i]==-1&&u[i+1]==0)||(u[i-1]==0&&u[i]==1&&u[i+1]==-1))){
					auto temp=u;
					swap(temp[i-1], temp[i+1]);
					if (dist[temp]==0) {
						track[temp]=track[u];
						track[temp].push_back((u[i-1]==1&&u[i]==-1&&u[i+1]==0)?i:i+2);
						if (temp==target){
							int cur=0;
							while (cur<track[temp].size()){
								cout<<track[temp][cur++];
								for (int j=0;j<19&&cur<track[temp].size();j++){
									cout<<" "<<track[temp][cur++];
								}
								cout<<endl;
							}
							exit(0);
						}
						q.push(temp);
						dist[temp]=steps;
					}
				}
				if (u[i]==1&&u[i+1]==0||u[i]==0&&u[i+1]==-1){
					auto temp=u;
					swap(temp[i], temp[i+1]);
					if (dist[temp]==0){
						track[temp]=track[u];
						track[temp].push_back((u[i]==1&&u[i+1]==0)?i+1:i+2);
						if (temp==target){
							int cur=0;
							while (cur<track[temp].size()){
								cout<<track[temp][cur++];
								for (int j=0;j<19&&cur<track[temp].size();j++){
									cout<<" "<<track[temp][cur++];
								}
								cout<<endl;
							}
							exit(0);
						}
						q.push(temp);
						dist[temp]=steps;
					}
				}
			}
		}
		steps++;
	}
}