/*
ID: michael419
LANG: C++
TASK: window
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

#define f first
#define s second
#define ll long long

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

deque<pair<pair<pair<int, int>, pair<int, int>>, char>> windows;
double ans1=0;

vector<int> extract_nums(const string &x){
	int cur=4, c=0;
	vector<int> ans;
	for (int i=cur;i<x.size()-1;i++){
		if (x[i]==','){
			ans.push_back(c);
			c=0;
		} else {
			c*=10;
			c+=x[i]-'0';
		}
	}
	ans.push_back(c);
	return ans;
}

void float_up(int k, int x1, int x2, int y1, int y2){
	while (k>=0&&(y1>=windows[k].f.s.s||y2<=windows[k].f.s.f||x1>=windows[k].f.f.s||x2<=windows[k].f.f.f)) k--;
	if (k==-1){
		ans1+=abs(x2-x1)*abs(y2-y1);
		return;
	}
	if (y2>windows[k].f.s.s){
		float_up(k-1, x1, x2, max(y1, windows[k].f.s.s), y2);
		y2=windows[k].f.s.s;
	}
	if (y1<windows[k].f.s.f){
		float_up(k-1, x1, x2, y1, min(y2, windows[k].f.s.f));
		y1=windows[k].f.s.f;
	}
	if (x2>windows[k].f.f.s) float_up(k-1, max(x1, windows[k].f.f.s), x2, y1, y2);
	if (x1<windows[k].f.f.f) float_up(k-1, x1, min(x2, windows[k].f.f.f), y1, y2);
}

int main(){
	setIO("window");
	string cmd;
	auto it=windows.begin();
	char item;
	vector<int> nums;
	while (cin>>cmd){
		switch (cmd[0]){
			case 'w':
				nums=extract_nums(cmd);
				if (nums[2]<nums[0]) swap(nums[2], nums[0]);
				if (nums[3]<nums[1]) swap(nums[3], nums[1]);
				windows.push_front({{{nums[0], nums[2]}, {nums[1], nums[3]}}, cmd[2]});
				break;
			case 't':
				it=windows.begin();
				item=cmd[2];
				for (;it!=windows.end();it++){
					auto full_item=(*it);
					if (full_item.s==item){
						windows.erase(it);
						windows.push_front(full_item);
						break;
					}
				}
				break;
			case 'd':
				item=cmd[2];
				it=windows.begin();
				for (;it!=windows.end();it++){
					auto full_item=(*it);
					if (full_item.s==item){
						windows.erase(it);
						break;
					}
				}
				break;
			case 'b':
				item=cmd[2];
				it=windows.begin();
				for (;it!=windows.end();it++){
					auto full_item=(*it);
					if (full_item.s==item){
						windows.erase(it);
						windows.push_back(full_item);
						break;
					}
				}
				break;
			case 's':
				item=cmd[2];
				for (int i=0;i<windows.size();i++){
					auto full_item=windows[i];
					if (full_item.s==item){
						ans1=0;
						float_up(i-1, full_item.f.f.f, full_item.f.f.s, full_item.f.s.f, full_item.f.s.s);
						double res=ans1/((full_item.f.f.s-full_item.f.f.f)*(full_item.f.s.s-full_item.f.s.f))*100;
						printf("%.3f\n", res);
						break;
					}
				}
				break;
		}
	}
}