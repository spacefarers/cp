/*
ID: michael419
LANG: C++14
TASK: hidden
*/
#include <bits/stdc++.h>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("hidden");
	int n;
	string a;
	cin>>n>>a;
	while (a.size()<n){
		string x;
		cin>>x;
		a+=x;
	}
	a=a+a;
	int left=0, right=1;
	while (right<n){
		int i;
		for (i=0;i<n;i++){
			if (a[left+i]!=a[right+i]) break;
		}
		if (a[left+i]==a[right+i]) break;
		if (a[left+i]>a[right+i]) left+=i+1;
		else right+=i+1;
		if (left==right) right++;
	}
	cout<<left<<endl;
}