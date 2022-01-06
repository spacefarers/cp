#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int last=0, last_cut=0;
		vector<int> max_ans, min_ans;
		priority_queue<int> avail_max;
		priority_queue<int, vector<int>, greater<>> avail_min;
		for (int i=0;i<n;i++){
			int temp;
			cin>>temp;
			if (temp!=last){
				for (int j=last+1;j<temp;j++){
					avail_max.push(j);
					avail_min.push(j);
				}
				last=temp;
				i-last_cut;
				max_ans.push_back(temp);
				min_ans.push_back(temp);
			} else {
				int a=avail_max.top(),b=avail_min.top();
				avail_max.pop();
				avail_min.pop();
				max_ans.push_back(a);
				min_ans.push_back(b);
			}
		}
		for (auto &i:min_ans){
			cout<<i<<" ";
		}
		cout<<endl;
		for (auto &i:max_ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}
}