#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> possibs;

int N;
long long pow(int a, int b){
	long long ans=1;
	for (int i=0;i<b;i++){
		ans*=a;
	}
	return ans;
}

int nums[7]={2,3,5,7,11,13,17};

vector<int> c;
vector<int> ans;
void possib(){
	if (c.size()==4){
		possibs.push_back(c);
		return;
	}
	for (auto &i:nums){
		c.push_back(i);
		possib();
		c.pop_back();
	}
}

int main(){
	cin>>N;
	possib();
	for (auto &i:possibs){
		int x=i[0]*i[1]*i[2]*i[3];
		if (x>10000) continue;
		ans.push_back(x);
	}
	for (auto &item:possibs){
		for (int i=1;pow(item[0],i)<10000;i++){
			for (int j=1;pow(item[1],j)<10000;j++){
				for (int k=1;pow(item[2],k)<10000;k++){
					for (int l=1;pow(item[3],l)<10000;l++){
						if (i+j+k+l==4) continue;
						long long c_val=pow(item[0],i)*pow(item[1],j)*pow(item[2],k)*pow(item[3],l);
						if (c_val<10000){
							ans.push_back((int)c_val);
						}
					}
				}
			}
		}
	}
	for (int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}
}