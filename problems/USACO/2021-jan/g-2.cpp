#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

string breeds[55];
int dist[50005];

#define s second
#define f first

int main(){
	int N, K;
	cin>>N>>K;
	vector<int> cows, breed_cows[55];
	for (int i=0;i<N;i++){
		int a;
		cin>>a;
		cows.push_back(a-1);
		breed_cows[a-1].push_back(i);
	}
	for (int i=0;i<K;i++){
		cin>>breeds[i];
	}
	memset(dist, 0x3f, sizeof dist);
	dist[0]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	q.push({0, 0});
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (dist[u.s]<u.f) continue;
		for (int i=0;i<K;i++){
			if (breeds[cows[u.s]][i]=='0') continue;
			vector<int> tests;
			if (!breed_cows[i].empty()) {
				tests.push_back(breed_cows[i].front());
				tests.push_back(breed_cows[i].back());
			}
			auto it=lower_bound(breed_cows[i].begin(), breed_cows[i].end(), u.s);
			if (it!=breed_cows[i].end())
				tests.push_back(*it);
			if (it!=breed_cows[i].begin()) {
				it--;
				tests.push_back(*it);
			}
			for (auto &k:tests){
				if (dist[k]>u.f+abs(k-u.s)){
					dist[k]=u.f+abs(k-u.s);
					q.push({dist[k], k});
				}
			}
		}
	}
	if (dist[N-1]>1e8) dist[N-1]=-1;
	cout<<dist[N-1]<<endl;
}