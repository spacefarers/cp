#include <iostream>

using namespace std;

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
//	setIO("E");
	int t, x;
	cin>>t>>x;
	for (int i=1;i<=t;i++){
		pair<int,int> max_win={0,0};
		for (int j=0;j<100;j++){
			string a;
			cin>>a;
			int c_win=0;
			for (auto &k:a){
				if (k=='1') c_win++;
			}
			if (max_win.first<c_win){
				max_win={c_win, j+1};
			}
		}
		cout<<"Case #"<<i<<": "<<max_win.second<<endl;
	}
}