#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	vector v {1, 23, 3, 2};
	merge_sort(v);
	/*string a;
	cin>>a;
	vector<int> nums = vector<int>(a.size()/2, 0);
	for (int i=0;i<a.size();i+=2)
		nums[i/2] = a[i];
	nums = sort(nums);
	string ans = "";
	for (int i=0;i<a.size()/2-1;i++)
		ans+=(nums[i] + "+");
	ans += nums[a.size()/2];
	cout<<ans<<endl;*/
}

vector<int> merge_sort(vector<int> array){
	if (array.size() == 1)
		return array;
	vector<int>::const_iterator begin = arr.begin();
	vector<int>::const_iterator last = arr.begin() + arr.size();
	vector<int> new_arr1(begin, begin+arr.size()/2);
	vector<int> new_arr2(begin+arr.size()/2, last);
	int i, j;
	i=0;
	j=0;
	vector<int> merged_arr = vector<int>(new_arr1.size()+new_arr2.size(), 0);
	for (int a;a<new_arr2.size();a++){
		while(new_arr1[i] < new_arr2[a] & i < new_arr1.size()){
			merged_arr[j] = new_arr1[i];
			j++;
		}
		merged_arr[j] = new_arr2[a];
		j++;
	}
	return merged_arr;
}
