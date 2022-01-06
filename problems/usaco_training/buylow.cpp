/*
ID: michael419
LANG: C++
TASK: buylow
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void setIO(const string &name){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

struct BigInt {
	static const int M=200;
	int num[M+10]{},len{};

	BigInt(){clean();}

	explicit BigInt(const string &x){
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

	void setVal(const string &x){
		clean();
		len=x.size();
		for (auto &i:x){
			num[len--]=i-'0';
		}
		len=x.size();
	}

	string output(){
		string ans;
		for (int i=len;i>=1;i--){
			ans+=to_string(num[i]);
		}
		return ans;
	}

	bool operator<(const BigInt &cmp) const{
		if (len!=cmp.len) return len<cmp.len;
		for (int i=len;i>=1;i--){
			if (num[i]!=cmp.num[i]) return num[i]<cmp.num[i];
		}
		return false;
	}

	bool operator>(const BigInt &cmp) const{return cmp<*this;}

	bool operator<=(const BigInt &cmp) const{return !(cmp<*this);}

	bool operator!=(const BigInt &cmp) const{return cmp<*this||*this<cmp;}

	bool operator==(const BigInt &cmp) const{return !(cmp<*this||*this<cmp);}

	BigInt operator+(const BigInt &A) const{
		BigInt S;
		S.len=max(len,A.len);
		for (int i=1;i<=S.len;i++){
			S.num[i]+=num[i]+A.num[i];
			if (S.num[i]>=10) {
				S.num[i]-=10;
				S.num[i+1]++;
			}
		}
		while (S.num[S.len+1]) S.len++;
		return S;
	}

	BigInt operator-(const BigInt &A) const{
		BigInt S;
		S.len=max(len,A.len);
		for (int i=1;i<=S.len;i++){
			S.num[i]+=num[i]-A.num[i];
			if (S.num[i]<0) {
				S.num[i]+=10;
				S.num[i+1]--;
			}
		}
		while (!S.num[S.len]&&S.len>1) S.len--;
		return S;
	}

	BigInt operator*(const BigInt &A) const{
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

int prices[5005],dp[5005];

int main(){
//	setIO("buylow");
	BigInt ans[5005];
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>prices[i];
	n++;
	prices[0]=1e9;
	prices[n]=0;
	ans[0]=ans[0]+BigInt(1);
	for (int i=1;i<=n;i++){
		int max_dp=0;
		for (int j=1;j<i;j++){
			if (prices[j]>prices[i]) {
				max_dp=max(max_dp,dp[j]);
			}
		}
		dp[i]=max_dp+1;
		for (int j=0;j<i;j++){
			if (prices[j]>prices[i]&&dp[j]==max_dp) {
				ans[i]=ans[i]+ans[j];
			}
		}
		for (int j=0;j<i;j++){
			if (prices[i]==prices[j]&&dp[i]==dp[j]) ans[i]=ans[i]-ans[j];
		}
	}
	cout<<dp[n]-1<<" "<<ans[n].output()<<endl;
}