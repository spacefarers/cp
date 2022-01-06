/*
ID: michael419
LANG: C++14
TASK: twofive
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

#define f first
#define s second

int f[6][6][6][6][6];
char set_tobe[30];

int dfs(int a, int b, int c, int d, int e, char s){
	if (s=='Z') return 1;
	int &x=f[a][b][c][d][e];
	if (x!=0) return f[a][b][c][d][e];
	if (a<5&&(!set_tobe[a]||set_tobe[a]==s)) x+=dfs(a+1,b,c,d,e,char(s+1));
	if (b<a&&(!set_tobe[b+5]||set_tobe[b+5]==s)) x+=dfs(a,b+1,c,d,e,char(s+1));
	if (c<b&&(!set_tobe[c+10]||set_tobe[c+10]==s)) x+=dfs(a,b,c+1,d,e,char(s+1));
	if (d<c&&(!set_tobe[d+15]||set_tobe[d+15]==s)) x+=dfs(a,b,c,d+1,e,char(s+1));
	if (e<d&&(!set_tobe[e+20]||set_tobe[e+20]==s)) x+=dfs(a,b,c,d,e+1,char(s+1));
	return x;
}

int main(){
	setIO("twofive");
	char a;
	cin>>a;
	if (a=='N'){
		int x;
		cin>>x;
		for (int i=0;i<25;i++){
			int s=0;
			memset(f, 0, sizeof f);
			for (set_tobe[i]='A';(s=dfs(0,0,0,0,0,'A'))<x;set_tobe[i]++){
				x-=s;
				memset(f, 0, sizeof f);
			}
		}
		cout<<set_tobe<<endl;
	} else {
		string x;
		cin>>x;
		int ans=1;
		for (int i=0;i<25;i++){
			for (set_tobe[i]='A';set_tobe[i]<x[i];set_tobe[i]++){
				memset(f, 0, sizeof f);
				ans+=dfs(0,0,0,0,0,'A');
			}
		}
		cout<<ans<<endl;
	}
}