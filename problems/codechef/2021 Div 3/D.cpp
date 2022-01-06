#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		int n, m;
		cin>>n>>m;
		vector<string> board;
		int min_x=0x7fffffff, min_y=0x7fffffff, max_x=0, max_y=0, num_ones=0;
		for (int i=0;i<n;i++){
			string a;
			cin>>a;
			board.push_back(a);
			for (int j=0;j<m;j++){
				if (a[j]=='1'){
					num_ones++;
					min_x=min(min_x, i);
					min_y=min(min_y, j);
					max_x=max(max_x, i);
					max_y=max(max_y, j);
				}
			}
		}
		if ((max_x-min_x+1)*(max_y-min_y+1)==num_ones) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}