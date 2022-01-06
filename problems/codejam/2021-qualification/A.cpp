#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		int n;
		cin>>n;
		vector<int> arr(n);
		for (int j=0;j<n;j++){
			cin>>arr[j];
		}
		int ans=0;
		for (int j=0;j<n-1;j++){
			pair<int, int> min_ele={1e9,0};
			for (int k=j;k<n;k++){
				if (arr[k]<min_ele.first) min_ele={arr[k],k};
			}
			ans+=min_ele.second-j+1;
			reverse(arr.begin()+j,arr.begin()+min_ele.second+1);
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}