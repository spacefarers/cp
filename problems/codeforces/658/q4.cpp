#include <iostream>
#include <vector>

using namespace std;

vector<int> current_comb;

bool possible_comb(vector<int> processing, int n){
	int all_sum=0;
	for (int i=0;i<current_comb.size();i++){
		all_sum += current_comb[i];
	}
	if (all_sum > n)
		return false;
	else if (all_sum == n)
		return true;
	for (int i=0;i<processing.size();i++){
		if (count(current_comb.begin(), current_comb.end(), processing[i]))
			continue;
		current_comb.push_back(processing[i]);
		if (possible_comb(processing, n))
			return true;
		current_comb.pop_back();
	}
	return false;
}

int main(){
	int test_cases;
	cin>>test_cases;
	for (int i=0;i<test_cases;i++){
		int n;
		cin>>n;
		vector<int> processing;
		vector<int> inputs;
		for (int j=0;j<2*n;j++){
			int a;
			cin>>a;
			inputs.push_back(a);
		}
		int biggest_num = 0;
		int biggest_num_index = -1;
		while (biggest_num_index != 0){
			for (int j=0; j<inputs.size();j++){
				if (inputs[j]>biggest_num){
					biggest_num = inputs[j];
					biggest_num_index = j;
				}
			}
			processing.push_back(inputs.size()-biggest_num_index-1);
			vector<int> tmp = vetor<int>(inputs.size()-biggest_num_index);
			copy(inputs.begin(), inputs.begin() + biggest_num_index, tmp.begin());
			cout<<"haha"<<endl;
			inputs = tmp;
		}
		cout<<(possible_comb(processing, n)?"YES":"NO")<<endl;
	}
	return 0;
}
