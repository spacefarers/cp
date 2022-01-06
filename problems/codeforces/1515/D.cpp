#include <iostream>
#include <map>

#define s second
#define f first

using namespace std;

int main(){
	int t;
	cin>>t;
	while (t--){
		int n, l, r;
		cin>>n>>l>>r;
		map<int,int> left_matches,right_matches;
		for (int i=0;i<l;i++){
			int a;
			cin>>a;
			left_matches[a]++;
		}
		for (int i=0;i<r;i++){
			int a;
			cin>>a;
			right_matches[a]++;
		}
		for (auto &i:left_matches){
			int match=min(i.s,right_matches[i.f]);
			l-=match,r-=match;
			i.s-=match,right_matches[i.f]-=match;
		}
		int pairs_left=0,pairs_right=0;
		for (auto &i:left_matches){
			pairs_left+=i.s/2;
		}
		for (auto &i:right_matches){
			pairs_right+=i.s/2;
		}
		int ans=min(l,r);
		if (l>r){
			ans+=l-r;
			ans-=min((l-r)/2,pairs_left);
		} else if (r>l){
			ans+=r-l;
			ans-=min((r-l)/2,pairs_right);
		}
		cout<<ans<<endl;
	}
}