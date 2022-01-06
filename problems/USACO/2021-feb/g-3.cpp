#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll full[40];
vector<ll> pow3=[](){
	vector<ll> ans={1};
	for (int i=1;i<40;i++){
		ans.push_back(ans.back()*3);
	}
	return ans;
}();

void gen_full(int k, ll dif){
	dif=abs(dif);
	if (k==0){
		full[k]=(dif==0);
	} else if (dif>=pow3[k-1]){
		gen_full(k-1, dif-2*pow3[k-1]);
		full[k]=full[k-1];
	} else {
		gen_full(k-1, dif);
		full[k]=3*full[k-1];
	}
}

ll rec(ll x, ll y, int k){
	x%=pow3[k];y%=pow3[k];
	if (k==0) return 1;
	if (x<y) swap(x, y);
	if (x-y>=pow3[k-1]){
		if (x<2*pow3[k-1]) return 0;
		if (y<pow3[k-1]) return rec(x, y, k-1);
		if (y>=pow3[k-1]) return full[k-1];
	}
	if (x<pow3[k-1]) return rec(x, y, k-1);
	if (y < pow3[k-1]) return full[k-1];
	if (x < 2*pow3[k-1]) return full[k-1]+rec(x,y,k-1);
	if (y < 2*pow3[k-1]) return 2*full[k-1];
	return 2*full[k-1]+rec(x,y,k-1);
}

ll diag(ll x, ll y){
	if (x<0||y<0) return 0;
	gen_full(39, x-y);
	return rec(x, y, 39);
}

int main(){
	int Q;
	cin>>Q;
	while (Q--){
		ll d, x, y;
		cin>>d>>x>>y;
		cout<<diag(x+d, y+d)-diag(x-1, y-1)<<endl;
	}
}