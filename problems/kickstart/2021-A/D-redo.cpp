#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int max_num[505], father[1005];

int find(int x){
	if (father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

void unionn(int a, int b){
	int c=find(a),d=find(b);
	father[c]=d;
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int n;
		cin>>n;
		int no_use;
		for (int j=0;j<n;j++){
			father[j]=j;
			father[j+n]=j+n;
			for (int k=0;k<n;k++){
				cin>>no_use;
			}
		}
		int tot=0;
		memset(max_num, 0, sizeof max_num);
		priority_queue<pair<int, pair<int, int>>> q;
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				int a;
				cin>>a;
				if (a!=0) q.push({a, {k, j}});
				tot+=a;
			}
		}
		for (int j=0;j<n;j++) cin>>no_use;
		for (int j=0;j<n;j++) cin>>no_use;
		while (!q.empty()){
			auto u=q.top();
			q.pop();
			if (find(u.second.first)!=find(u.second.second+n)){
				unionn(u.second.first, u.second.second+n);
				tot-=u.first;
			}
		}
		cout<<"Case #"<<i<<": "<<tot<<endl;
	}
}