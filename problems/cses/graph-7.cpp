#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int n, m, dist_m[1005][1005], dist_p[1005][1005];
pair<pi, char> trace[1005][1005];
string maze[1005];
vpi monsters, finish;
pi player;

bool valid(pi a){
	return a.f>=0&&a.s>=0&&a.f<n&&a.s<m&&maze[a.f][a.s]!='#';
}

int main() {
//    setIO("");
	pair<pi, char> d[4]={{{-1, 0}, 'U'}, {{1, 0}, 'D'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
	cin>>n>>m;
	for (int i=0;i<n;++i){
		cin>>maze[i];
		for (int j=0;j<m;++j){
			if (maze[i][j]=='M'){
				monsters.pb({i, j});
			} else if (maze[i][j]=='A') {
				player={i, j};
			}
		}
	}
	memset(dist_p, -1, sizeof dist_p);
	memset(dist_m, -1, sizeof dist_m);
	queue<pi> bfs_q;
	trav(i, monsters) {bfs_q.push(i);dist_m[i.f][i.s]=0;}
	int step=1;
	while (!bfs_q.empty()){
		int sz=bfs_q.size();
		for (int i=0;i<sz;++i){
			auto u=bfs_q.front();
			bfs_q.pop();
			trav(j, d){
				pi new_u={u.f+j.f.f, u.s+j.f.s};
				if (!valid(new_u)) continue;
				if (dist_m[new_u.f][new_u.s]==-1){
					dist_m[new_u.f][new_u.s]=step;
					bfs_q.push(new_u);
				}
			}
		}
		step++;
	}
	bfs_q.push(player);
	dist_p[player.f][player.s]=0;
	step=1;
	while (!bfs_q.empty()){
		int sz=bfs_q.size();
		for (int i=0;i<sz;++i){
			auto u=bfs_q.front();
			bfs_q.pop();
			trav(j, d){
				pi new_u={u.f+j.f.f, u.s+j.f.s};
				if (!valid(new_u)) continue;
				if (dist_p[new_u.f][new_u.s]==-1){
					dist_p[new_u.f][new_u.s]=step;
					trace[new_u.f][new_u.s]={u, j.s};
					bfs_q.push(new_u);
				}
			}
		}
		step++;
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if ((i==0||j==0||i==n-1||j==m-1)&&maze[i][j]!='#'&&(dist_m[i][j]>dist_p[i][j]||dist_m[i][j]==-1)&&dist_p[i][j]!=-1){
				string ans;
				pi u={i, j};
				while (maze[u.f][u.s]!='A'){
					ans+=trace[u.f][u.s].s;
					u=trace[u.f][u.s].f;
				}
				reverse(all(ans));
				cout<<"YES"<<endl<<ans.size()<<endl<<ans<<endl;
				exit(0);
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

