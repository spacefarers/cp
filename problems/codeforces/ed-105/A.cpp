#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int represent[3];
bool all_ok;
string a;

void test(){
	bool ok=true;
	vector<int> x;
	for (auto &j:a){
		x.push_back(represent[j-'A']);
	}
	int counts=0;
	for (auto &j:x){
		if (j==1) counts++;
		else counts--;
		if (counts<0){
			ok=false;
		}
	}
	if (ok&&counts==0) all_ok=true;
}

int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>a;
		if (a.front()==a.back()||a.size()%2){
			cout<<"NO"<<endl;
			continue;
		}
		memset(represent, 0, sizeof represent);
		represent[a.front()-'A']=1;
		represent[a.back()-'A']=-1;
		all_ok=false;
		for (auto &i:represent){
			if (i==0){
				i=1;
				test();
				i=-1;
				test();
			}
		}
		if (all_ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}