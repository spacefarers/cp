#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sums[2505][2505];

#define all(x) x.begin(), x.end()

int sum_area(int x1, int y1, int x2, int y2){
	return sums[x2+1][y2+1]-sums[x1][y2+1]-sums[x2+1][y1]+sums[x1][y1];
}

int main(){
	int n;
	cin>>n;
	vector<pair<int, int>> cows;
	for (int i=0;i<n;i++){
		int a, b;
		cin>>a>>b;
		cows.emplace_back(a, b);
	}
	sort(all(cows));
	for (int i=0;i<n;i++){
		cows[i].first=i+1;
	}
	sort(all(cows), [](pair<int, int> a, pair<int, int> b)->bool{return a.second<b.second;});
	for (int i=0;i<n;i++){
		cows[i].second=i+1;
	}
	for (int i=0;i<n;i++){
		sums[cows[i].first][cows[i].second]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			sums[i][j]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
		}
	}
	long long ans=0;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			int minx=min(cows[i].first, cows[j].first)-1;
			int maxx=max(cows[i].first, cows[j].first)-1;
			ans+=sum_area(0, i, minx, j)*sum_area(maxx, i, n-1, j);
		}
	}
	cout<<ans+1<<endl;
}