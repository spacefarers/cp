#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int ins[3];
		cin>>ins[0]>>ins[1]>>ins[2];
		sort(ins,ins+3);
		if (ins[1]!=ins[2]){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<ins[0]<<" "<<ins[0]<<" "<<ins[1]<<endl;
	}
	return 0;
}
