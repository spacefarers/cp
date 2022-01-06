/*
ID: michael419
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	int n;
	fin>>n;
	int day=0;
	int days_count[] = {0, 0, 0, 0, 0, 0, 0};
	for (int i=1900;i<1900+n;i++){
		bool leap = false;
		if ((i%4==0) & (i%100!=0 || i%400==0)){
			// leap year
			leap=true;
		}
		for (int j=1;j<=12;j++){
			days_count[(day+1)%7]++;
			if (j==1||j==3||j==5||j==7||j==8||j==10||j==12)
				day+=3;
			else if (j == 2)
				day+=(leap?1:0);
			else
				day+=2;
			day%=7;
		}
	}
	for (int i=1;i<7;i++)
		fout<<days_count[i]<<" ";
	fout<<days_count[0]<<endl;
	return 0;
}
