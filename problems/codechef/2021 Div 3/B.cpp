#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		int N, K;
		cin>>N>>K;
		vector<int> values;
		for (int i=0;i<K;i++){
			int a;
			cin>>a;
			values.push_back(a);
		}
		for (int i=0;i<N;i++){
			string a;
			cin>>a;
			long long points=0;
			for (int j=0;j<K;j++){
				if (a[j]=='1') points+=values[j];
			}
			cout<<points<<endl;
		}
	}
}