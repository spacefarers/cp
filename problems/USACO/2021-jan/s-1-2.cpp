#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int arr[100005], f_ans[100005];
bool ans[100005];
vector<pair<int, int>> swaps;

int main(){
	int n, k;
	cin>>n>>k;
	for (int i=0;i<=n;i++){
		arr[i]=i;
	}
	for (int i=0;i<k;i++){
		int a, b;
		cin>>a>>b;
		swaps.emplace_back(a, b);
		swap(arr[a], arr[b]);
	}
	for (int i=1;i<=n;i++){
		if (f_ans[i]!=0) {
			cout<<f_ans[i]<<endl;
			continue;
		}
		memset(ans, false, sizeof ans);
		ans[i]=true;
		int t=i;
		while (true){
			for (auto &j:swaps){
				if (j.first==t) {
					ans[j.second]=true;
					t=j.second;
				} else if (j.second==t) {
					ans[j.first]=true;
					t=j.first;
				}
			}
			if (i==t) break;
		}
		int c_ans=0;
		for (int j=1;j<=n;j++){
			if (ans[j]) c_ans++;
		}
		for (int j=1;j<=n;j++){
			if (ans[j]) f_ans[j]=c_ans;
		}
		cout<<c_ans<<endl;
	}
}