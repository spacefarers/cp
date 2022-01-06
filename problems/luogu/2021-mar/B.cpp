#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

ll poww(ll a,ll b){
	ll ans=1;
	for (int i=0;i<b;i++){
		ans*=a;
	}
	return ans;
}

bool actions[1000005];
int pos[1055], new_pos[1055];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll h,m;
	cin>>h>>m;
	ll n=poww(2,h);
	if (h<=10) {
		for (int i=0;i<n;i++){
			pos[i]=i;
		}
		for (int i=0;i<m;i++){
			ll a,b;
			cin>>a>>b;
			if (a==1) {
				int u=0, y=1;
				if (b==1) swap(u, y);
				for (int j=u;j<n;j+=2){
					new_pos[j/2]=pos[j];
				}
				for (int j=y;j<n;j+=2){
					new_pos[j/2+n/2]=pos[j];
				}
				for (int j=0;j<1055;j++){
					pos[j]=new_pos[j];
				}
			} else {
				cout<<pos[b]<<endl;
			}
		}
	} else {
		ll cur=0;
		int cons_0=0,cons_1=0;
		for (int i=0;i<m;i++){
			ll a,b;
			cin>>a>>b;
			if (a==1) {
				actions[cur++]=b==0;
				if (b==0) {
					cons_0++;
					cons_1=0;
				} else {
					cons_1++;
					cons_0=0;
				}
				if (cons_0==h) {
					cur-=h;
					cons_0=0;
				} else if (cons_1==2*h) {
					cur-=2*h;
					cons_1=0;
				}
			} else {
				ll cur1=b;
				for (ll j=cur-1;j>=0;j--){
					auto action=actions[j];
					if (cur1>=n/2) {
						cur1-=n/2;
						cur1*=2;
						if (action) cur1++;
					} else {
						cur1*=2;
						if (!action) cur1++;
					}
				}
				cout<<cur1<<endl;
			}
		}
	}
}