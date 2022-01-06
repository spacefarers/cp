#include <iostream>
#include <queue>

using namespace std;

long long ans[100005];

int main(){
	long long K,N,M,m;
	cin>>K>>N>>M;
	m=M;
	priority_queue<pair<long long,long long>> q;
	for (int i=0;i<K;i++){
		long long x;
		cin>>x;
		x*=m;
		long long take_away=x/N;
		M-=take_away;
		x-=take_away*N;
		ans[i]=take_away;
		q.push({x,i});
	}
	for (int i=0;i<M;i++){
		auto u=q.top();
		q.pop();
		u.first=N-u.first;
		ans[u.second]++;
	}
	for (int i=0;i<K;i++){
		cout<<ans[i]<<" ";
	}
}

//68,372  56,488