#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
int n;
bool board[1005][1005];

void flip_col(int x){
	for (int i=0;i<n;i++){
		board[i][x]=!board[i][x];
	}
}
void flip_row(int x){
	for (int i=0;i<n;i++){
		board[x][i]=!board[x][i];
	}
}

int main() {
//    setIO("leftout");
	cin>>n;
	for (int i=0;i<n;i++){
		string a;
		cin>>a;
		for (int j=0;j<n;j++){
			board[i][j]=a[j]=='R';
		}
	}
	for (int i=0;i<n;i++){
		if (!board[i][0]) flip_row(i);
	}
	for (int i=0;i<n;i++){
		if (!board[0][i]) flip_col(i);
	}
	pi first;
	int full_row_ma;
	bool set=false, full=true, sset=false;
	for (int i=n-1;i>0;i--){
		bool full_row=true;
		for (int j=n-1;j>0;j--){
			if (!board[i][j]) {first={i, j};sset=true;}
			else {full_row=false;full=false;}
		}
		if (full_row) {
			set=true;
			full_row_ma=i;
		}
	}
	if (full) cout<<"1 1"<<endl;
	else if (set) cout<<full_row_ma+1<<" 1"<<endl;
	else if (sset) cout<<first.f+1<<" "<<first.s+1<<endl;
	else cout<<-1<<endl;
	return 0;
}

