#include <iostream>

using namespace std;

bool board[1005][1005];
int value[1005][1005];
int n, max_ans=0;

int check_box(int x1, int y1){
	int ans=0;
	if (board[x1][y1]) ans++;
	if (board[x1+1][y1+1]) ans++;
	if (board[x1][y1+1]) ans++;
	if (board[x1+1][y1]) ans++;
	return ans;
}

void dfs(int x1, int y1){
	int c_ans=-1;
//	for (int i=0;i<n;i++){
//		for (int j=0;j<n;j++){
//			if (board[i][j]) cout<<"C";
//			else cout<<".";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	pair<int, int> next={x1+1, y1};
	if (next.first>=n) {
		next.first=0;
		next.second++;
	}
	if (y1>=n) {
		int c_ans2=0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i!=0&&j!=0&&check_box(i-1, j-1)!=2) return;
				if (board[i][j]) c_ans2+=value[i][j];
			}
		}
		max_ans=max(max_ans, c_ans2);
		return;
	}
	if (x1!=0&&y1!=0) {
		int res=check_box(x1-1, y1-1);
		if (res<2) c_ans=1;
		else c_ans=0;
	}
	if (c_ans!=-1){
		board[x1][y1]=c_ans;
		dfs(next.first, next.second);
	} else {
		if (y1!=0) {
			int res=check_box(x1, y1-1);
			if (res==0) c_ans=1;
			else if (res==2) c_ans=0;
		}
		if (c_ans!=-1) {
			board[x1][y1]=c_ans;
			dfs(next.first, next.second);
		} else {
			board[x1][y1]=true;
			dfs(next.first, next.second);
			board[x1][y1]=false;
			dfs(next.first, next.second);
		}
	}
	board[x1][y1]=false;
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>value[i][j];
		}
	}
	dfs(0, 0);
	cout<<max_ans<<endl;
}