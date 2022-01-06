#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

bool used[26];
int dp[1500000];
int mp[150][150];

int main(){
	string a;
	cin>>a;
	for (auto &i:a){
		used[i-'a']=true;
	}
	for (int i=0;i<a.size()-1;i++){
		mp[a[i]][a[i+1]]++;
	}
	vector<char> letters;
	for (int i='a';i<='z';i++){
		if (used[i-'a']) letters.push_back(i);
	}
//	sort(letters.begin(), letters.end());
//	int ans=0x7fffffff;
//	do {
//		int c_ans=0;
//		for (int i=0;i<letters.size();i++){
//			for (int j=i;j<letters.size();j++){
//				c_ans+=mp[{letters[j], letters[i]}];
//			}
//		}
//		ans=min(ans, c_ans+1);
//	} while (next_permutation(letters.begin(), letters.end()));
	memset(dp, 0x3f, sizeof dp);
	dp[0]=1;
	for (int i=1;i<(1<<letters.size());i++){
		dp[i]=a.size();
		for (int j=0;j<letters.size();j++){
			if ((i&(1<<j))!=0){
				int sum=dp[i^(1<<j)];
				for (int k=0;k<letters.size();k++){
					if ((i&(1<<k))!=0) sum+=mp[letters[j]][letters[k]];
				}
				dp[i]=min(dp[i], sum);
			}
		}
	}
	cout<<dp[(1<<letters.size())-1]<<endl;
}