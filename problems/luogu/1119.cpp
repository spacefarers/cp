#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int paths[205][205];

int main(){
	int N, M;
	cin>>N>>M;
	vector<int> times(N);
	for (int i=0;i<N;i++){
		cin>>times[i];
	}
	memset(paths, 0x3f, sizeof paths);
	for (int i=0;i<M;i++){
		int a, b, c;
		cin>>a>>b>>c;
		paths[a][b]=c;
		paths[b][a]=c;
	}
	int q;
	cin>>q;
	int cur=0;
	while (q--){
		int x, y, t;
		cin>>x>>y>>t;
		while (cur<N&&t>=times[cur]){
			for (int i=0;i<N;i++){
				for (int j=0;j<N;j++){
					paths[i][j]=min(paths[i][j], paths[i][cur]+paths[cur][j]);
				}
			}
			cur++;
		}
		if (paths[x][y]>1e8||x>=cur||y>=cur) cout<<-1<<endl;
		else cout<<paths[x][y]<<endl;
	}
}