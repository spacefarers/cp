/*
ID: michael419
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	map<string, int> bank;
	int n;
	fin>>n;
	vector<string> names = vector<string>(n, "");
	for (int i=0;i<n;i++){
		string name;
		fin>>name;
		bank[name] = 0;
		names[i] = name;
	}
	for (int i=0;i<n;i++){
		string name;
		int amount, num_people;
		fin>>name>>amount>>num_people;
		if (num_people==0)
			continue;
		bank[name] -= (amount-amount%num_people);
		for (int j=0;j<num_people;j++){
			string name_rec;
			fin>>name_rec;
			bank[name_rec] += amount/num_people;
		}
	}
	for (int i=0; i<names.size();i++){
		fout<<names[i]<<" "<<bank[names[i]]<<endl;
	}

    return 0;
}
