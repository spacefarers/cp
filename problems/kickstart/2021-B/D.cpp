#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define ll long long

vector<pair<int,pair<int,ll>>> paths[50005];
pair<int,pair<int,ll>> trace[50005];
vector<pair<int,ll>> precomp[50005];
vector<ll> prefix[50005];

void dfs(int x,int from){
	for (auto &i:paths[x]){
		if (i.first!=from) {
			trace[i.first]={x,i.second};
			dfs(i.first,x);
		}
	}
}

ll gcd(ll a,ll b){
	if (b==0) return a;
	return gcd(b,a%b);
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int N,Q;
		cin>>N>>Q;
		for (auto &path:paths){
			path.clear();
		}
		for (auto &j:precomp){
			j.clear();
		}
		for (auto &j:prefix){
			j.clear();
		}
		for (int j=1;j<N;j++){
			int a,b,c;
			ll d;
			cin>>a>>b>>c>>d;
			paths[a].push_back({b,{c,d}});
			paths[b].push_back({a,{c,d}});
		}
		dfs(1,-1);
		for (int j=1;j<N;j++){
			paths[j].clear();
			paths[j].shrink_to_fit();
		}
		for (int j=2;j<=N;j++){
			int c=j;
			while (c!=1){
				precomp[j].push_back(trace[c].second);
				c=trace[c].first;
			}
			sort(precomp[j].begin(),precomp[j].end());
			ll h=precomp[j].front().second;
			prefix[j].push_back(0);
			for (int k=1;k<=precomp[j].size();k++){
				h=gcd(h,precomp[j][k-1].second);
				prefix[j].push_back(h);
			}
		}
		cout<<"Case #"<<i<<": ";
		for (int j=0;j<Q;j++){
			int a,b;
			cin>>a>>b;
			int z=-1;
			for (int k=((int)precomp[a].size()+1)/2;k>=1;k/=2){
				while (z+k<precomp[a].size()&&b>=precomp[a][z+k].first) z+=k;
			}
			cout<<prefix[a][z+1]<<" ";
		}
		cout<<endl;
	}
}