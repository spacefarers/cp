/*
ID: michael419
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second


void setIO(const string& name) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int poww(int a, int b){
    int ans=1;
    for (int i=0;i<b;i++){
        ans*=a;
    }
    return ans;
}

int main() {
	setIO("dualpal");
	int n, s, c=0;
	cin>>n>>s;
	while (c!=n){
		s++;
		int i, cc=0;
		for (i=2;i<=10;i++){
            int temp=s;
            string a;
			int factor=30;
			while (temp>0){
				if (pow(i, factor)>temp){
					factor--;
					a+="0";
					continue;
				}
				int num=temp/poww(i, factor);
				a+=to_string(num);
				temp-=num*poww(i, factor);
				factor--;
			}
			for (int j=0;j<=factor;j++) a+="0";
			int left=0, right=a.size()-1;
			while (a[left]=='0') left++;
			bool ook=true;
			while (left<right){
//				cout<<"test: "<<a[left]<<" "<<a[right]<<endl;
				if (a[left]!=a[right]){
					ook=false;
					break;
				}
				left++;
				right--;
			}
			if (ook){
			    cc++;
			}
		}
		if (cc>=2){
            c++;
            cout<<s<<endl;
		}
	}
    return 0;
}
