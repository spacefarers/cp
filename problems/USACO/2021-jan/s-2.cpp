#include <iostream>
#include <queue>

using namespace std;

int front[100005], back[100005];

int main(){
	int n, q;
	cin>>n>>q;
	string input;
	cin>>input;
	deque<int> qu;
	for (int i=0;i<n;i++){
		while (!qu.empty()&&qu.back()>input[i]) qu.pop_back();
		if (!qu.empty()&&qu.back()==input[i]){
			front[i]=front[i-1];
		} else {
			if (i==0) front[i]=1;
			else front[i]=front[i-1]+1;
			qu.push_back(input[i]);
		}
	}
	qu.clear();
	for (int i=n-1;i>=0;i--){
		while (!qu.empty()&&qu.back()>input[i]) qu.pop_back();
		if (!qu.empty()&&qu.back()==input[i]){
			back[i]=back[i+1];
		} else {
			back[i]=back[i+1]+1;
			qu.push_back(input[i]);
		}
	}
	for (int i=0;i<q;i++){
		int a, b;
		cin>>a>>b;
		a-=2;
		int x=0, y=0;
		if (a>=0) x=front[a];
		if (b<n) y=back[b];
		cout<<x+y<<endl;
	}
}