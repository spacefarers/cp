/*
ID: michael419
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int n;

int m_mod(int a, int b){
    a%=b;
    a+=b;
    a%=b;
    return a;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	string beads;
	fin>>n>>beads;
	int max_l = 0;
	for (int i=0;i<beads.size();i++){
	    int reached;
	    int length=0;
	    char fixed='w';
	    for (int j=i-1;m_mod(j, beads.size())!=i;j--){
	        int u=m_mod(j, beads.size());
	        if (fixed != 'w'){
                if (fixed != beads[u] && beads[u] != 'w') break;
	        } else {
	            fixed = beads[u];
	        }
            length++;
	        reached = u;
	    }
	    fixed='w';
	    for (int j=i;m_mod(j, beads.size())!=reached;j++){
            int u=m_mod(j, beads.size());
            if (fixed != 'w'){
                if (fixed != beads[u] && beads[u] != 'w') break;
            } else {
                fixed = beads[u];
            }
            length++;
	    }
	    max_l = max(max_l, length);
	}
	fout<<max_l<<endl;
    return 0;
}
