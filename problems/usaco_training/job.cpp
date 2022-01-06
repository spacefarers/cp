/*
ID: michael419
LANG: C++
TASK: job
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define ll long long
#define f first
#define s second

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}
vector<ll> A_time, B_time;
ll N, M1, M2, time1[1005], time2[1005], machines1[35], machines2[35];

int main(){
	setIO("job");
	cin>>N>>M1>>M2;
	for (int i=1;i<=M1;i++){
		int x;
		cin>>x;
		A_time.push_back(x);
	}
	for (int i=1;i<=M2;i++){
		int x;
		cin>>x;
		B_time.push_back(x);
	}
	for (int i=0;i<N;i++){
		pair<ll, ll> min_ans={1e15, -1};
		for (int j=0;j<M1;j++){
			if ((machines1[j]+1)*A_time[j]<min_ans.f) {
				min_ans={(machines1[j]+1)*A_time[j], j};
			}
		}
		machines1[min_ans.s]++;
		time1[i]=min_ans.f;
	}
	cout<<time1[N-1]<<" ";
	for (int i=0;i<N;i++){
		pair<ll, ll> min_ans={1e15, -1};
		for (int j=0;j<M2;j++){
			if ((machines2[j]+1)*B_time[j]<min_ans.f) {
				min_ans={(machines2[j]+1)*B_time[j], j};
			}
		}
		machines2[min_ans.s]++;
		time2[i]=min_ans.f;
	}
	ll ans=0;
	for (int i=0;i<N;i++){
		ans=max(ans, time1[i]+time2[N-i-1]);
	}
	cout<<ans<<endl;
}