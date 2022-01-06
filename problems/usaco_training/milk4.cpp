/*
ID: michael419
LANG: C++
TASK: milk4
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int q, depth;
vector<int> track,ans;
vector<int> pails;

void dfs(int price,int last_item, int dep){
//	if (!ans.empty()&&track.size()>ans.size()||last_item>=pails.size()) return;
	if (dep==depth+1){
		if (price==q){
			if (ans.empty()||track.size()<ans.size()||(ans.size()==track.size()&&track<ans)) {
				ans=track;
			}
		}
		return;
	}
	if (price>q) return;
	int m=1;
	if (last_item>=pails.size()) return;
	track.push_back(pails[last_item]);
	while (pails[last_item]*m+price<=q){
		dfs(pails[last_item]*m+price,last_item+1, dep+1);
		m++;
	}
	track.pop_back();
	if (last_item<pails.size()) dfs(price, last_item+1, dep);
}

int main(){
	setIO("milk4");
	cin>>q;
	int p;
	cin>>p;
	for (int i=0;i<p;i++){
		int a;
		cin>>a;
		bool ok=true;
		for (int &pail:pails){
			if (pail%a==0) {
				pail=a;
				break;
			} else if (a%pail==0) {
				ok=false;
				break;
			}
		}
		if (ok) pails.push_back(a);
	}
	sort(pails.begin(),pails.end());
	for (depth=1;depth<=pails.size();depth++){
//		cout<<depth<<endl;
		dfs(0,0,1);
		if (!ans.empty()) break;
	}
	cout<<ans.size();
	for (auto &i:ans){
		cout<<" "<<i;
	}
	cout<<endl;
}