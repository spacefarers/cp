/*
ID: michael419
LANG: C++
TASK: lgame
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

vector<int> input_composition;

vector<int> disect(const string &x){
	vector<int> ans(26);
	for (auto &i:x){
		ans[i-'a']++;
	}
	return ans;
}

bool compact(const vector<int> &x){
	for (int i=0;i<26;i++){
		if (x[i]>input_composition[i]) return false;
	}
	return true;
}

int worth[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
set<vector<int>> pos[55];

int main(){
	setIO("lgame");
	fstream file("lgame.dict");
	string input;
	cin>>input;
	input_composition=disect(input);
	string temp;
	file>>temp;
	vector<string> dict;
	map<vector<int>,vector<string>> mp;
	mp[vector<int>(26)].push_back("");
	while (temp!="."){
		mp[disect(temp)].push_back(temp);
		dict.push_back(temp);
		file>>temp;
	}

	vector<pair<int,int>> all_input;
	int all_worth=0;
	for (int i=0;i<26;i++){
		all_worth+=worth[i]*input_composition[i];
		for (int j=0;j<input_composition[i];j++) all_input.emplace_back(i, worth[i]);
	}
	pos[0].insert(vector<int>(26));
	for (auto &i:all_input){
		for (int j=all_worth;j>=i.second;j--){
			for (auto &k:pos[j-i.second]){
				vector<int> x(26);
				for (int l=0;l<26;l++) x[l]=k[l];
				x[i.first]++;
				pos[j].insert(x);
			}
		}
	}
	int min_take=0x7fffffff;
	vector<pair<string, string>> ans;
	for (const string &i:dict){
		auto working_composition=disect(i);
		if (!compact(working_composition)) continue;
		for (int j=0;j<=min(all_worth, min_take);j++){
			for (auto &k:pos[j]){
				bool ok=true;
				vector<int> new_arr(26);
				for (int l=0;l<26;l++){
					new_arr[l]=input_composition[l]-k[l]-working_composition[l];
					if (new_arr[l]<0){
						ok=false;
						break;
					}
				}
				if (!ok) continue;
				if (!mp[new_arr].empty()){
					if (j<min_take){
						min_take=j;
						ans.clear();
					} else if (j!=min_take) continue;
					for (const string& l:mp[new_arr]){
						ans.emplace_back(i, l);
					}
				}
			}
		}
	}
	cout<<all_worth-min_take<<endl;
	set<pair<string, string>> f_ans;
	for (auto &i:ans){
		if ((i.first>i.second||i.first.empty())&&!i.second.empty()) swap(i.first, i.second);
		f_ans.insert({i.first, i.second});
	}
	for (auto &i:f_ans){
		if (i.second.empty()) cout<<i.first<<endl;
		else cout<<i.first<<" "<<i.second<<endl;
	}
}