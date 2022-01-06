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
