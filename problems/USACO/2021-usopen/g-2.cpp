#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,pair<pair<int,int>,pair<int,int>>>> edges;
int father[200100];

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a),d=find(b);
	father[c]=d;
}

int main(){
	int n;
	cin>>n;
	for (int i=0;i<2*n+10;i++){
		father[i]=i;
	}
	for (int i=0;i<n;i++){
		int a, b, c, d, e;
		cin>>a>>b>>c>>d>>e;
		edges.push_back({a,{{b,c},{d,e}}});
		unionn(b,c);
		unionn(d,e);
	}
	sort(edges.begin(),edges.end());
	int ans=0;
	for (auto &i:edges){
		if (find(i.second.first.first)!=find(i.second.second.first)){
			ans+=i.first;
			unionn(i.second.first.first,i.second.second.first);
		}
	}
	cout<<ans<<endl;
}