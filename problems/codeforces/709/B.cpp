#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(){
	int t;
	cin>>t;
	while (t--){
		ll n;
		cin>>n;
		vector<ll> inputs(n);
		for (int i=0;i<n;i++){
			cin>>inputs[i];
		}
		ll dif=-1, rev_dif=1;
		for (int i=0;i<n-1;i++){
			ll c_dif=inputs[i+1]-inputs[i];
			if (c_dif>=0){
				if (dif==-1) dif=c_dif;
				else if (dif!=c_dif){
					cout<<-1<<endl;
					goto cont;
				}
			} else {
				if (rev_dif==1) rev_dif=c_dif;
				else if (rev_dif!=c_dif){
					cout<<-1<<endl;
					goto cont;
				}
			}
		}
		if (dif!=-1&&rev_dif!=1) {
			for (int i=1;i<n;i++){
				if (inputs[i-1]>dif-rev_dif||(inputs[i-1]+dif)%(dif-rev_dif)!=inputs[i]){
					cout<<-1<<endl;
					goto cont;
				}
			}
		}
		if (dif==-1||rev_dif==1){
			cout<<0<<endl;
		} else cout<<dif-rev_dif<<" "<<dif<<endl;
		cont:;
	}
}