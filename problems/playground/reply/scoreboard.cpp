#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+"_input.txt").c_str(), "r", stdin);
	freopen((name+"_output.txt").c_str(), "w", stdout);
}

bool status[5005][6][6];
int time_stamps[5005];

int main(){
	setIO("p1");
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int N, L;
		cin>>N>>L;
		for (int j=0;j<L;j++){
			int time, team, problem, input, scored;
			cin>>time>>team>>problem>>input>>scored;
			if (scored==0) continue;
			time_stamps[team]=time;
			status[team][problem][input]=true;
		}
		vector<pair<pair<int, int>, int>> teams;
		for (int j=1;j<=N;j++){
			int points=0;
			for (int k=1;k<=5;k++){
				for (int l=1;l<=5;l++){
					if (status[j][k][l]) points+=l*100;
				}
			}
			teams.push_back({{points, time_stamps[j]}, j});
		}
		sort(teams.begin(), teams.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
			if (a.first!=b.first) return a.first>b.first;
			return a.second<b.second;
		});
		cout<<"Case #"<<i<<":";
		for (auto &j:teams){
			cout<<" "<<j.second;
		}
		cout<<endl;
	}
}