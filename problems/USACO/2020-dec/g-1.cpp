#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define f first
#define s second
#define ll long long

string board[1005];

ll dist_rock[1005][1005],dist_start[1005][1005],life[1005][1005];
ll n,d;
bool has_robot[1005][1005],temp[1005][1005];

pair<ll,ll> dirs[4]={{0, 1},
                       {0, -1},
                       {1, 0},
                       {-1,0}};
queue<pair<ll,ll>> q;

bool valid(pair<ll,ll> pos){
	return pos.f>=0&&pos.s>=0&&pos.f<n&&pos.s<n&&board[pos.f][pos.s]!='#';
}

void bfs(ll (&dist_arr)[1005][1005]){
	ll steps=1;
	while (!q.empty()){
		ll sz=q.size();
		while (sz--){
			auto u=q.front();
			q.pop();
			for (auto &i:dirs){
				auto new_pos=u;
				new_pos.f+=i.f;
				new_pos.s+=i.s;
				if (valid(new_pos)&&dist_arr[new_pos.f][new_pos.s]==(ll)1e9) {
					dist_arr[new_pos.f][new_pos.s]=steps;
					q.push({new_pos.f,new_pos.s});
				}
			}
		}
		steps++;
	}
}

int main(){
	cin>>n>>d;
	vector<pair<ll,ll>> starts;
	for (ll i=0;i<n;i++){
		cin>>board[i];
		for (ll j=0;j<n;j++){
			dist_rock[i][j]=1e9;
			if (board[i][j]=='S') {
				starts.emplace_back(i,j);
				dist_start[i][j]=0;
				has_robot[i][j]=true;
			} else if (board[i][j]=='#') {
				q.push({i,j});
				dist_rock[i][j]=0;
			}
		}
	}
	bfs(dist_rock);
	for (auto &i:starts){
		q.push(i);
	}
	vector<pair<pair<ll,ll>,ll>> centers;
	ll steps=0;
	while (!q.empty()){
		ll sz=q.size();
		while (sz--){
			auto u=q.front();
			q.pop();
			if (steps==dist_rock[u.f][u.s]*d) continue;
			for (auto &i:dirs){
				auto new_pos=u;
				new_pos.f+=i.f;
				new_pos.s+=i.s;
				if (valid(new_pos)&&(steps+1)<=dist_rock[new_pos.f][new_pos.s]*d&&!has_robot[new_pos.f][new_pos.s]) {
					centers.push_back({{new_pos.f,new_pos.s},dist_rock[new_pos.f][new_pos.s]-1});
					has_robot[new_pos.f][new_pos.s]=true;
					q.push(new_pos);
					board[new_pos.f][new_pos.s]='C';
					life[new_pos.f][new_pos.s]=dist_rock[new_pos.f][new_pos.s]-1;
				}
			}
		}
		steps++;
	}
	for (auto &i:centers){
		if (i.s>0)
			q.push(i.f);
	}
	while (!q.empty()){
		ll sz=q.size();
		while (sz--){
			auto u=q.front();
			q.pop();
			for (auto &dir:dirs){
				auto new_pos=u;
				new_pos.f+=dir.f;
				new_pos.s+=dir.s;
				if (valid(new_pos)&&(life[new_pos.f][new_pos.s]<life[u.f][u.s]-1||!has_robot[new_pos.f][new_pos.s])) {
					has_robot[new_pos.f][new_pos.s]=true;
					life[new_pos.f][new_pos.s]=life[u.f][u.s]-1;
					if (life[new_pos.f][new_pos.s]>0)
						q.push({new_pos.f,new_pos.s});
				}
			}
		}
	}
	ll ans=0;
	for (ll i=0;i<n;i++){
		for (ll j=0;j<n;j++){
			if (has_robot[i][j]) ans++;
			if (board[i][j]=='.'&&has_robot[i][j]) board[i][j]='X';
//			cout<<board[i][j];
		}
//		cout<<endl;
	}
	cout<<ans<<endl;
}