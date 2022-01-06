#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cows[200005], last_breed[200005], last_from[200005], next_from[200005];
vector<pair<int, int>> ranges;
int tree[200005];
int n;

int sum(int k){
	int s=0;
	while (k>=1){
		s+=tree[k];
		k-=k&(-k);
	}
	return s;
}

void add(int k){
	while (k<=n){
		tree[k]++;
		k+=k&(-k);
	}
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		next_from[i]=n+1;
		cin>>cows[i];
		if (last_breed[cows[i]]!=0){
			next_from[last_breed[cows[i]]]=i;
		}
		last_from[i]=last_breed[cows[i]];
		last_breed[cows[i]]=i;
	}
	for (int i=1;i<=n;i++){
		ranges.emplace_back(i,next_from[i]);
	}
	sort(ranges.begin(), ranges.end(), [](pair<int,int> a, pair<int,int> b){
		return a.second<b.second;
	});
	long long ans=0;
	for (int i=n;i>=1;i--){
		while (!ranges.empty()&&ranges.back().second>i){
			add(ranges.back().first);
			ranges.pop_back();
		}
		ans+=(sum(i-1)-sum(last_from[i]));
	}
	cout<<ans<<endl;
}