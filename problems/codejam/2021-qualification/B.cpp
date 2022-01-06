#include <iostream>

using namespace std;

int x,y;

int cal_ans(int blanks,char start,char end){
	int min_ans=1e9;
	if (start==end||start==-1||end==-1) min_ans=0;
	else {
		if (start=='C') min_ans=min(min_ans,x);
		else min_ans=min(min_ans,y);
	}
	if ((start==-1&&end=='J')||(end==-1&&start=='C')) min_ans=min(min_ans, x);
	if ((start==-1&&end=='C')||(end==-1&&start=='J')) min_ans=min(min_ans, y);
	if (start!=-1&&end!=-1) {
		bool start_val=true;
		if (start!='C') start_val=false;
		int c_ans=0;
		for (int i=0;i<blanks;i++){
			c_ans+=(start_val)?x:y;
			start_val^=true;
		}
		if (start_val^(end=='C')) {
			c_ans+=(start_val)?x:y;
		}
		min_ans=min(min_ans,c_ans);
	} else {
		int minority=blanks/2,majority=(blanks+1)/2;
		if (start=='C'||end=='J') {
			min_ans=min(min_ans,minority*y+majority*x);
		} else if (start=='J'||end=='C') {
			min_ans=min(min_ans,majority*y+minority*x);
		}
	}
	return min_ans;
}

int main(){
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		string a;
		cin>>x>>y>>a;
		int ans=0;
		for (int j=0;j<a.size()-1;j++){
			string cut=a.substr(j,2);
			if (cut=="CJ") ans+=x;
			else if (cut=="JC") ans+=y;
		}
		int blanks=0;
		char start=-1;
		for (int j=0;j<a.size();j++){
			if (a[j]=='?') {
				blanks++;
			} else {
				if (blanks!=0) {
					ans+=cal_ans(blanks,start,a[j]);
					blanks=0;
				}
				start=a[j];
			}
		}
		if (blanks!=0) ans+=cal_ans(blanks,start,-1);
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}