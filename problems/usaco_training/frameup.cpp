/*
ID: michael419
LANG: C++
TASK: frameup
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

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

string board[35];
int min_x[26], max_x[26], min_y[26], max_y[26], deg[26];
bool has_letter[26];
set<int> paths[26];
string c_ans;
bool vis[26];
vector<string> ans;

void dfs(int x){
	if (vis[x]) return;
	vis[x]=true;
	c_ans+=char(x+'A');
	for (auto &i:paths[x]) deg[i]--;
	if (all_of(vis, vis+26, [](bool a){return a;})) ans.push_back(c_ans);
	for (int i=0;i<26;i++) if (deg[i]==0) dfs(i);
	for (auto &i:paths[x]) deg[i]++;
	c_ans=c_ans.substr(0, c_ans.size()-1);
	vis[x]=false;
}

void check_top(char check1, char check2, int i){
	if (check1!='.'&&i!=check1-'A'){
		if (paths[check1-'A'].find(i)==paths[check1-'A'].end()) {
			deg[i]++;
			paths[check1-'A'].insert(i);
		}
	}
	if (check2!='.'&&i!=check2-'A'){
		if (paths[check2-'A'].find(i)==paths[check2-'A'].end()) {
			deg[i]++;
			paths[check2-'A'].insert(i);
		}
	}
}

int main(){
	setIO("frameup");
	int H, W;
	cin>>H>>W;
	memset(min_x, 0x7f, sizeof min_x);
	memset(min_y, 0x7f, sizeof min_y);
	for (int i=0;i<H;i++){
		cin>>board[i];
		for (int j=0;j<W;j++){
			if (board[i][j]=='.') continue;
			int letter=board[i][j]-'A';
			min_x[letter]=min(min_x[letter], i);
			min_y[letter]=min(min_y[letter], j);
			max_x[letter]=max(max_x[letter], i);
			max_y[letter]=max(max_y[letter], j);
			has_letter[letter]=true;
		}
	}
	for (int i=0;i<26;i++){
		if (!has_letter[i]) continue;
		for (int j=min_x[i];j<=max_x[i];j++){
			char check1=board[j][min_y[i]], check2=board[j][max_y[i]];
			check_top(check1, check2, i);
		}
		for (int j=min_y[i];j<max_y[i];j++){
			char check1=board[min_x[i]][j], check2=board[max_x[i]][j];
			check_top(check1, check2, i);
		}
	}
	vector<int> q;
	for (int i=0;i<26;i++){
		if (deg[i]==0&&has_letter[i]) q.push_back(i);
		if (!has_letter[i]) vis[i]=true;
	}
	for (auto &i:q){
		dfs(i);
	}
	for (auto &i:ans) reverse(i.begin(), i.end());
	sort(ans.begin(), ans.end());
	for (auto &i:ans){
		cout<<i<<endl;
	}
}