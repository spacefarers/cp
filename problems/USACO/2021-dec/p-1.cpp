//
// Created by michaelyang on 4:53 PM Dec 20 2021.
// Problem: Problem 1. Tickets

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long

using namespace std;

ll price_to_1[1005],price_to_n[1005],oneTrack[1005],NTrack[1005],oneTrackP[1005],NTrackP[1005];
ll p1min[1005][1005],p2min[1005][1005];

pair<pair<int,int>,pair<int,int>> tickets[1005];
vector<pair<int,pair<int,int>>> rev_tickets[1005];

void dijkstra(int pos,ll*list,ll*track,ll*trackP){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> q;
	q.push({0,pos});
	while (!q.empty()){
		auto u=q.top();
		q.pop();
		if (u.f!=list[u.s]) continue;
		for (auto&i:rev_tickets[u.s]){
			if (list[i.s.s]>list[u.s]+i.s.f){
				list[i.s.s]=list[u.s]+i.s.f;
				track[i.s.s]=i.f;
				trackP[i.s.s]=u.s;
				q.push({list[i.s.s],i.s.s});
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,K;
	cin>>n>>K;
	memset(price_to_1,0x7f,sizeof price_to_1);
	memset(price_to_n,0x7f,sizeof price_to_n);
	memset(oneTrack,-1,sizeof oneTrack);
	memset(NTrack,-1,sizeof NTrack);
	for (int i=0;i<K;i++){
		int c,p,a,b;
		cin>>c>>p>>a>>b;
		tickets[i]={{c,p},
		            {a,b}};
		for (int j=a;j<=b;j++){
			rev_tickets[j].push_back({i,{p,c}});
		}
	}
	price_to_1[1]=0;
	price_to_n[n]=0;
	dijkstra(1,price_to_1,oneTrack,oneTrackP);
	dijkstra(n,price_to_n,NTrack,NTrackP);

	memset(p1min,0x7f,sizeof p1min);
	memset(p2min,0x7f,sizeof p2min);

	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			p1min[i][j]=min(p1min[i][j-1],price_to_1[j]);
			p2min[i][j]=min(p2min[i][j-1],price_to_n[j]);
		}
	}

	for (int i=1;i<=n;i++){
		if (price_to_1[i]>=(ll)1e12||price_to_n[i]>=(ll)1e12){
			cout<<-1<<endl;
			continue;
		} else{
			ll ans=0;
			int c=i;
			ll minPrice=price_to_n[c],onePrice=0;
			while (c!=1){
				minPrice=min(minPrice,p2min[tickets[oneTrack[c]].s.f][tickets[oneTrack[c]].s.s]);
				onePrice+=tickets[oneTrack[c]].f.s;
				c=oneTrackP[c];
			}
			ans=minPrice+onePrice;

			c=i;
			minPrice=price_to_1[c];
			ll nPrice=0;
			while (c!=n){
				minPrice=min(minPrice,p1min[tickets[NTrack[c]].s.f][tickets[NTrack[c]].s.s]);
				nPrice+=tickets[NTrack[c]].f.s;
				c=NTrackP[c];
			}
			cout<<min(ans,minPrice+nPrice)<<endl;
		}
	}
}

