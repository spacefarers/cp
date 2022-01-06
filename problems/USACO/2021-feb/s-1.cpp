#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int adj[2005][2005], ans[100005];
bool has_cow[2005][2005];
queue<pair<int, int>> trouble;
pair<int, int> dirs[4]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void add_cow(int a, int b){
	adj[a+1][b]++;
	adj[a-1][b]++;
	adj[a][b+1]++;
	adj[a][b-1]++;
	has_cow[a][b]=true;
}

void check_surrounds(int a, int b){
	if (has_cow[a+1][b]&&adj[a+1][b]==3){
		trouble.push({a+1, b});
	}
	if (has_cow[a-1][b]&&adj[a-1][b]==3){
		trouble.push({a-1, b});
	}
	if (has_cow[a][b+1]&&adj[a][b+1]==3){
		trouble.push({a, b+1});
	}
	if (has_cow[a][b-1]&&adj[a][b-1]==3){
		trouble.push({a, b-1});
	}
	if (has_cow[a][b]&&adj[a][b]==3){
		trouble.push({a, b});
	}
}

bool is_comfort(int a, int b){
	return adj[a][b]==3;
}

int main(){
	int N;
	cin>>N;
	vector<pair<int, int>> points;
	for (int i=0;i<N;i++){
		int a, b;
		cin>>a>>b;
		points.emplace_back(a, b);
	}
	int c_ans=0;
	for (int i=0;i<N;i++){
		int a=points[i].first, b=points[i].second;
		a+=500, b+=500;
		if (has_cow[a][b]){
			c_ans--;
			ans[i]=c_ans;
			continue;
		}
		add_cow(a, b);
		check_surrounds(a, b);
		while (!trouble.empty()){
			auto u=trouble.front();
			trouble.pop();
			if (!is_comfort(u.first, u.second)) continue;
			c_ans++;
			for (auto &j:dirs){
				if (!has_cow[u.first+j.first][u.second+j.second]){
					add_cow(u.first+j.first, u.second+j.second);
					check_surrounds(u.first+j.first, u.second+j.second);
					break;
				}
			}
		}
		ans[i]=c_ans;
	}
	for (int i=0;i<N;i++){
		cout<<ans[i]<<endl;
	}
}