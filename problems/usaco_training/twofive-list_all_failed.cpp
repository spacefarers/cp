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

string board[5];
int counts=0,stop_time=1e9;
basic_string<char,char_traits<char>,allocator<char>> match_string;
int space[5];
vector<string> test;

void generate_all(char c){
	if (counts%int(1e5)==0) cout<<counts<<endl;
	if (space[4]==5){
		counts++;
		string x;
		for (auto &i:board){
			x+=i;
		}
		test.push_back(x);
		if (counts==stop_time){
			cout<<x<<endl;
//			exit(0);
		} else if (x==match_string){
			cout<<counts<<endl;
//			exit(0);
		}
		return;
	}
	for (int i=0;i<5;i++){
		if (space[i]>=5) continue;
		if (i==0||space[i]<space[i-1]){
			board[i][space[i]]=c;
			space[i]++;
			generate_all(char(c+1));
			space[i]--;
		}
	}
}


int main(){
//	setIO("twofive");
	for (auto &i:board){
		i="$$$$$";
	}
	char a;
	cin>>a;
	if (a=='N'){
		int b;
		cin>>b;
		stop_time=b;
	} else {
		string b;
		cin>>b;
		match_string=b;
	}
	generate_all('A');
	cout<<test.size()<<endl;
}