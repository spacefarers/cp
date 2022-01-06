#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
int N;
bool entered[100005];
ll c[100005];

int lowbit(int x) {
	return x&(-x);
}

void update(int x, int v) {
	for(int i=x;i<=2*N;i+=lowbit(i))
		c[i]+=v;
}

ll getSum(int x) {
	ll ans=0;
	for(int i=x; i>0; i-=lowbit(i))
		ans+=c[i];
	return ans;
}

void setIO(const string& name) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("circlecross");
	cin>>N;
	vector<pair<int, int>> cows(N+1);
	for (int i=1;i<=2*N;i++){
		int a;
		cin>>a;
		if (!entered[a]){
			cows[a].first=i;
			entered[a]=true;
		} else {
			cows[a].second=i;
		}
	}
	sort(cows.begin(), cows.end());
	cows.erase(cows.begin());
	ll ans=0;
	for (auto &i:cows){
		ans+=getSum(i.second)-getSum(i.first-1);
		update(i.second, 1);
	}
	cout<<ans<<endl;
}