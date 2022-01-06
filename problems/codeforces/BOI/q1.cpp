#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c, n, ph;
vector<int> obtained;

bool visited(int q){
	//for (int i=0;i<obtained.size();i++) cout<<obtained[i]<<" ";
	//cout<<endl;
	return find(obtained.begin(), obtained.end(), q) != obtained.end();
}

bool try_num(int q){
	if (c-q>0){
		cout<<"? "<<c-q<<endl;
		c-=q;
		obtained.push_back(c);
	} else if (c+q<=n && !visited(c+q)){
		cout<<"? "<<c+q<<endl;
		c+=q;
		obtained.push_back(c);
	} else {
		for (int i=1; i<=n;i++){
			if (visited(i)) continue;
			if ((i-q>0 && !visited(i-q)) || (i+q<n && !visited(i+q))){
				cout<<"? "<<i<<endl;
				c=i;
				cin>>ph;
				obtained.push_back(i);
				return try_num(q);
			}
		}
		return false;
	}
	bool ans;
	cin>>ans;
	return ans;
}

int main(){
	int test_cases;
	cin >> test_cases;
	for (int i=0;i<test_cases;i++){
		obtained = vector<int>();
		cin>>n;
		int big=n, sml=0, f_ans, q;
		c=n;
		cout<<"? "<<n<<endl;
		obtained.push_back(n);
		cin>>ph;
		while (big-sml > 1){
			q = sml+(big-sml)/2;
			bool ans = try_num(q);
			if (!ans)
				sml=q;
			else {
				big=q;
				f_ans=q;
			}
		}
		cout<<"= "<<f_ans<<endl;
	}
}
