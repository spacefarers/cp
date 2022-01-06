#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

int main(){
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		vector<pair<int, int>> points(n);
		for (int i=0;i<n;i++){
			cin>>points[i].first;
		}
		for (int i=0;i<n;i++){
			cin>>points[i].second;
		}
		sort(points.begin(), points.end());
		if (points.front()!=make_pair(1, 1)){
			points.insert(points.begin(), {1, 1});
		}
		n=points.size();
		int ans=0;
		for (int i=0;i<n-1;i++){
			auto a=points[i],b=points[i+1];
			int layer_a=(a.f-a.s)/2, layer_b=(b.f-b.s)/2;
			if ((a.f-a.s)%2){
				// a on highway, doesn't matter where b is as long as there exist an answer
				ans+=layer_b-layer_a;
			} else {
				if ((b.f-b.s)%2||layer_a!=layer_b) {
					// a not on highway but b on highway, b is not but they're not on the same layer
					ans+=layer_b-layer_a;
				} else {
					ans+=b.f-a.f;
				}
			}
		}
		cout<<ans<<endl;
	}
}