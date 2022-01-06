#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pi;

#define trav(a,x) for (auto& a: x)
#define sz(x) int(x.size())
#define f first
#define s second

string maze[1005];
bool visited[1005][1005];
int n, m;

bool valid(pi a){
	return maze[a.f][a.s]!='#'&&a.f>=0&&a.s>=0&&a.f<n&&a.s<m;
}
pi start, finish;

int main() {
	cin>>n>>m;
	pair<pi, char> d[4]={{{-1, 0}, 'U'}, {{1, 0}, 'D'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
	for (int i=0;i<n;i++){
		cin>>maze[i];
		for (int j=0;j<m;++j){
			if (maze[i][j]=='A') start={i, j};
			if (maze[i][j]=='B') finish={i, j};
		}
	}
	queue<pair<pi, string>> q;
	q.push({start, ""});
	int dep=0;
	while (!q.empty()){
		int sz=q.size();
		for (int i=0;i<sz;++i){
			auto u=q.front();
			q.pop();
			if (u.f==finish){
				cout<<"YES"<<endl<<dep<<endl<<u.s<<endl;
				return 0;
			}
			for (auto j : d){
				pi new_p={u.f.f+j.f.f, u.f.s+j.f.s};
				if (valid(new_p)&&!visited[new_p.f][new_p.s]) {
					visited[new_p.f][new_p.s]=true;
					q.push({new_p, u.s+j.s});
				}
			}
		}
		dep++;
	}
	cout<<"NO"<<endl;
	return 0;
}

