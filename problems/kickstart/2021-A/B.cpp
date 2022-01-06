#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool board[1005][1005];
int R, C;
pair<int, int> dirs[4]={{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down, left, up, right

bool isValid(int y, int x){
	return y>=0&&x>=0&&y<R&&x<C&&board[y][x];
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		memset(board, false, sizeof board);
		cin>>R>>C;
		for (int j=0;j<R;j++){
			for (int k=0;k<C;k++){
				cin>>board[j][k];
			}
		}
		int ans=0;
		for (int j=0;j<R;j++){
			for (int k=0;k<C;k++){
				// be an endpoint
				if (!board[j][k]) continue;
				vector<int> lengths;
				for (auto &l:dirs){
					int len=1;
					int new_y=j;
					int new_x=k;
					while (true){
						new_y+=l.first;
						new_x+=l.second;
						if (!isValid(new_y, new_x)) break;
						len++;
					}
					lengths.push_back(len);
				}
				for (int l=0;l<4;l++){
					// clockwise
					if (lengths[(l+1)%4]>=4&&lengths[l]>=2){
						ans+=(min(lengths[(l+1)%4]/2, lengths[l])-1);
					}
					// counter clockwise
					if (lengths[(l+3)%4]>=4&&lengths[l]>=2){
						ans+=(min(lengths[(l+3)%4]/2, lengths[l])-1);
					}
				}

			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}