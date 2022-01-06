#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<pair<int, int>> stops(n+1);
		vector<int> extra_time(n+1);
		stops[0]={0, 0};
		extra_time[0]=0;
		for (int i=1;i<=n;i++){
			cin>>stops[i].first>>stops[i].second;
		}
		for (int i=1;i<=n;i++) cin>>extra_time[i];
		int c_time=0;
		for (int i=1;i<=n;i++){
			c_time=max(stops[i-1].second, c_time+(int)ceil(double(stops[i-1].second-stops[i-1].first)/2));
			c_time+=stops[i].first-stops[i-1].second;
			c_time+=extra_time[i];
		}
		cout<<c_time<<endl;
	}
}