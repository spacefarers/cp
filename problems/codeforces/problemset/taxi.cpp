#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> inputs = vector<int>(n);
	int count2s = 0,count3s = 0,count1s=0;
	int ans = 0;
	for (int i=0; i<n;++i){
		cin>>inputs[i];
		switch (inputs[i]){
			case 1:
				count1s++;
				break;
			case 2:
				count2s++;
				break;
			case 3:
				count3s++;
				break;
			case 4:
				ans++;
				break;

		}
	}	ans += count2s/2;
	if (count2s % 2 == 1){
		ans++;
		count1s-= 2;
	}
	ans += count3s;
	count1s -= count3s;
	if (count1s>0){
		ans += ceil((double)count1s/4);
	}
	cout<<ans<<endl;
	return 0;
}
	
