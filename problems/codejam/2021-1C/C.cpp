#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

string not_op(const string &x){
	string new_x;
	for (auto &i:x){
		if (i=='0') new_x+='1';
		else new_x+='0';
	}
	while (new_x[0]=='0'&&new_x.size()>1) new_x=new_x.substr(1,new_x.size()-1);
	return new_x;
}

string double_op(const string &x){
	return x+'0';
}

map<string,int> mp;
map<int,string> rev_mp;
pair<int,int> paths[500000];
int counts=1;

void dfs(const string &x){
	if (x.size()>14) return;
	auto new_a=not_op(x);
	auto new_b=double_op(x);
	if (mp[new_a]==0){
		mp[new_a]=counts++;
		rev_mp[counts-1]=new_a;
		dfs(new_a);
	}
	if (mp[new_b]==0){
		mp[new_b]=counts++;
		rev_mp[counts-1]=new_b;
		dfs(new_b);
	}
	paths[mp[x]]={mp[new_a],mp[new_b]};
}

int dist[500000];

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		mp.clear();
		rev_mp.clear();
		counts=1;
		for (auto &j:paths){
			j={0,0};
		}
		string a, b;
		cin>>a>>b;
		dfs(a);
		priority_queue<pair<int,int>> q;
		memset(dist,0x3f,sizeof dist);
		q.push({0,mp[a]});
		dist[mp[a]]=0;
		while (!q.empty()){
			auto u=q.top();
			q.pop();
			if (u.first>dist[u.second]) continue;
			vector<int> pos={paths[u.second].first,paths[u.second].second};
			for (auto &j:pos){
				if (dist[j]>dist[u.second]+1){
					dist[j]=dist[u.second]+1;
					q.push({dist[j], j});
				}
			}
		}
		string ans=to_string(dist[mp[b]]);
		if (mp[b]==0) ans="IMPOSSIBLE";
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}