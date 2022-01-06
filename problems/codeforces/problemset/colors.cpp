#include <iostream>

using namespace std;

long long N;

bool validate(long long x){
	int a;
	cout<<"? 1"<<endl;
	fflush(stdout);
	cin>>a;
	cout<<"? "+to_string(1+x)<<endl;
	fflush(stdout);
	cin>>a;
	return a==1;
}

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>N;
		long long left=0, right=N;
		while (left<right){
			long long mid=(left+right)/2;
			if (validate(mid)){
				right=mid;
			} else {
				left=mid+1;
			}
		}
		cout<<"= "+to_string(left)<<endl;
		fflush(stdout);
	}
}
