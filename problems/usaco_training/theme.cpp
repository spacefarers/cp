/*
ID: michael419
LANG: C++
TASK: theme
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

map<int, vector<int>> occurances;
vector<int> melody;

int main(){
	setIO("theme");
	int N;
	cin>>N;
	int last;
	cin>>last;
	for (int i=0;i<N-1;i++){
		int a;
		cin>>a;
		melody.push_back(a-last);
		occurances[a-last].push_back(i);
		last=a;
	}
	int ans=0;
	for (auto &i:occurances){
		for (int j=0;j<i.s.size();j++){
			for (int k=j+1;k<i.s.size();k++){
				int length=1, x=i.s[j], y=i.s[k];
				if (y-x<ans||y>=N-ans) continue;
				while (x<N-1&&y<N-1&&melody[x]==melody[y]&&length+x<y){
					length++;
					x++;y++;
				}
				if (length>=5) ans=max(ans, length);
			}
		}
	}
	cout<<ans<<endl;
}