/*
ID: michael419
LANG: C++14
TASK: picture
*/
#include <bits/stdc++.h>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

#define f first
#define s second

int ans=0;
vector<pair<pair<int, int>, pair<int, int>>> rects;
map<int, int> track;
void solve(){
	vector<pair<int, int>> working[20010];
	for (auto &i:rects){
		working[i.f.f+10005].emplace_back(i.s.f, 1);
		working[i.f.f+10005].emplace_back(i.s.s, -1); // reverse the other edge so that we can better keep track of layers of rects
		working[i.f.s+10005].emplace_back(i.s.f, -1);
		working[i.f.s+10005].emplace_back(i.s.s, 1);
	}
	for (auto &i:working){
		for (auto &j:i){
			track[j.f]+=j.s;
			if (track[j.f]==0) track.erase(j.f);
		}
		int a=0;
		for (auto &k:track){
			if (a==0||a+k.s==0) ans++;
			a+=k.s;
		}
	}
}


int main(){
	setIO("picture");
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		rects.push_back({{a, c}, {b, d}}); // x then y
	}
	solve();
	for (auto &i:rects){
		swap(i.f, i.s);
	}
	solve();
	cout<<ans<<endl;
}