//
// Created by spacefarers on 9:51 PM Dec 11 2021.
// Problem: https://vjudge.net/problem/LightOJ-1068

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define f first
#define s second
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int MOD=1e9+7;

struct BigInt{
	static const int M=200;
	int num[M+10]{},len{};

	BigInt(){clean();}

	explicit BigInt(const string&x){
		clean();
		setVal(x);
	}

	explicit BigInt(int x){
		clean();
		setVal(to_string(x));
	}

	void clean(){
		memset(num,0,sizeof(num));
		len=1;
	}

	void setVal(const string&x){
		clean();
		len=(int)x.size();
		for (auto&i: x){
			num[len--]=i-'0';
		}
		len=(int)x.size();
	}

	string output(){
		string ans;
		for (int i=len;i>=1;i--){
			ans+=to_string(num[i]);
		}
		return ans;
	}

	bool operator<(const BigInt&cmp) const{
		if (len!=cmp.len) return len<cmp.len;
		for (int i=len;i>=1;i--){
			if (num[i]!=cmp.num[i]) return num[i]<cmp.num[i];
		}
		return false;
	}

	bool operator>(const BigInt&cmp) const{return cmp<*this;}

	bool operator<=(const BigInt&cmp) const{return !(cmp<*this);}

	bool operator!=(const BigInt&cmp) const{return cmp<*this||*this<cmp;}

	bool operator==(const BigInt&cmp) const{return !(cmp<*this||*this<cmp);}

	BigInt operator+(const BigInt&A) const{
		BigInt S;
		S.len=max(len,A.len);
		for (int i=1;i<=S.len;i++){
			S.num[i]+=num[i]+A.num[i];
			if (S.num[i]>=10){
				S.num[i]-=10;
				S.num[i+1]++;
			}
		}
		while (S.num[S.len+1]) S.len++;
		return S;
	}

	BigInt operator-(const BigInt&A) const{
		BigInt S;
		S.len=max(len,A.len);
		for (int i=1;i<=S.len;i++){
			S.num[i]+=num[i]-A.num[i];
			if (S.num[i]<0){
				S.num[i]+=10;
				S.num[i+1]--;
			}
		}
		while (!S.num[S.len]&&S.len>1) S.len--;
		return S;
	}

	BigInt operator*(const BigInt&A) const{
		BigInt S;
		if ((A.len==1&&A.num[1]==0)||(len==1&&num[1]==0)) return S;
		S.len=A.len+len-1;
		for (int i=1;i<=len;i++){
			for (int j=1;j<=A.len;j++){
				S.num[i+j-1]+=num[i]*A.num[j];
				S.num[i+j]+=S.num[i+j-1]/10;
				S.num[i+j-1]%=10;
			}
		}
		while (S.num[S.len+1]) S.len++;
		return S;
	}
};

BigInt f(BigInt x, BigInt k){
	BigInt dp[35][10005];
	dp[0][0]=BigInt(0);
	for (int j=1;j<33;j++){
		for (int i=0;BigInt(i)<=k;i++){
			
		}
		dp[j]
	}
}

int main(){
	fastio
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		string x,y,z;
		cin>>x>>y>>z;
		BigInt a(x),b(y),k(z);

		cout<<"Case "<<i<<": "<<endl;
	}
}

