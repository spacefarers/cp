#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, k;
	cin>>n>>k;
	vector<int> inputs;
	inputs = vector<int>(n, 0);
	for (int i=0;i<n;++i){
		cin>>inputs[i];
	}
	int threshold = inputs[k-1];
	int count =0;
	for (int i=0; i<n;++i){
		if (inputs[i]>0&inputs[i]>=threshold){
			count++;
		} else {
			break;
		}
	}
	cout<<count<<endl;
	return 0;
}
