//
// Created by spacefarers on 5:31 PM Nov 21 2021.
// Problem: G. Boom

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define f first
#define s second
#define ll long long

using namespace std;

deque<int> deck;
int cards[105][105],difficulty[105];
vector<string> points[105];
pair<pair<int,int>,pair<int,int>> teams[105];
string cardName[105];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,t;
	cin>>n>>t;
	for (int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		teams[i]={{a,b},{c,d}};
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		string x;
		int c;
		cin>>x>>c;
		deck.push_back(i);
		cardName[i]=x;
		difficulty[i]=c;
	}
	int cTeam=0;
	bool first=true;
	while (!deck.empty()){
		int cT=t;
		while (cT!=0){
			if (deck.empty()) break;
			int teamSkill=(first)?teams[cTeam].f.f+teams[cTeam].s.s:teams[cTeam].f.s+teams[cTeam].s.f;
			int teamTimeReq=max(1,difficulty[deck.front()]-teamSkill-cards[deck.front()][cTeam]);
			if (teamTimeReq<=cT){
				cT-=teamTimeReq;
				points[cTeam].push_back(cardName[deck.front()]);
				deck.pop_front();
			} else {
				deck.push_back(deck.front());
				cards[deck.front()][cTeam]+=cT;
				cT=0;
				deck.pop_front();
			}
		}
		cTeam++;
		if (cTeam%n==0){
			cTeam=0;
			first=!first;
		}
	}
	for (int i=0;i<n;i++){
		cout<<points[i].size();
		for (auto&j:points[i]){
			cout<<" "<<j;
		}
		cout<<endl;
	}
}

