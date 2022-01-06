/*
ID: michael419
LANG: C++
TASK: charrec
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
#include <unordered_map>
#include <fstream>

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

double chances[27];
string collect[1205];
int dp[1205],dif[27][20][1205];
vector<vector<string>> chars;
vector<string> input;
char c_ans;

int check_sim(int cur1,int cur2){
	int ans=400;
	for (int z=0;z<27;z++){
		auto i=chars[z];
		int prev=ans;
		if (cur2-cur1==19) {
			int min_unlike=400;
			for (int j=0;j<20;j++){
				int unlike=0;
				int cur=cur1;
				for (int k=0;k<20;k++){
					if (k==j) continue;
					unlike+=dif[z][k][cur++];
				}
				min_unlike=min(min_unlike,unlike);
			}
			ans=min(min_unlike,ans);
		} else if (cur2-cur1==20) {
			int cur=cur1,unlike=0;
			for (int k=0;k<20;k++){
				unlike+=dif[z][k][cur++];
			}
			ans=min(ans,unlike);
		} else {
			for (int j=0;j<20;j++){
				int unlike=0;
				int p=cur1;
				for (int k=0;k<j;k++) unlike+=dif[z][k][p++];
				unlike+=dif[z][j][p++];
				unlike+=dif[z][j][p++];
				for (int k=j+1;k<20;k++) unlike+=dif[z][k][p++];
				ans=min(ans, unlike);
			}
		}
		if (ans!=prev) {
			if (z==0) c_ans=' ';
			else c_ans=char('a'+z-1);
		}
	}
	return ans;
}

int main(){
	setIO("charrec");
	fstream font("font.in");
	int a;
	font>>a;
	for (int i=0;i<27;i++){
		vector<string> seq;
		for (int j=0;j<20;j++){
			string b;
			font>>b;
			seq.push_back(b);
		}
		chars.push_back(seq);
	}
	cin>>a;
	for (int i=0;i<a;i++){
		string b;
		cin>>b;
		input.push_back(b);
	}
	for (int i=0;i<27;i++){
		for (int j=0;j<20;j++){
			for (int k=0;k<a;k++){
				int x=0;
				for (int l=0;l<20;l++){
					if (chars[i][j][l]!=input[k][l]) x++;
				}
				dif[i][j][k]=x;
			}
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for (int i=0;i<a;i++){
		if (dp[i]>1e7) continue;
		int res;
		if (a<i+19) continue;
		res=check_sim(i,i+19);
		if (dp[i+19]>res+dp[i]) {
			dp[i+19]=res+dp[i];
			if (res>120) c_ans='?';
			collect[i+19]=collect[i]+c_ans;
		}
		if (a<i+20) continue;
		res=check_sim(i,i+20);
		if (dp[i+20]>res+dp[i]) {
			dp[i+20]=res+dp[i];
			if (res>120) c_ans='?';
			collect[i+20]=collect[i]+c_ans;
		}
		if (a<i+21) continue;
		res=check_sim(i,i+21);
		if (res>=400) continue;
		if (dp[i+21]>res+dp[i]) {
			dp[i+21]=res+dp[i];
			if (res>120) c_ans='?';
			collect[i+21]=collect[i]+c_ans;
		}
	}
	cout<<collect[a]<<endl;
}