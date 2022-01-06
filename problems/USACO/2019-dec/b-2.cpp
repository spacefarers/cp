/*
ID: michael419
LANG: C++
TASK: whereami
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");
    int n, i;
    string a;
    fin>>n>>a;
    for (i=1;i<n;i++){
        bool ok=true;
        for (int j=0;j<n;j++){
            string current_str = a.substr(j, i);
            for (int k=j+1;k<n;k++){
                if (current_str.compare(a.substr(k, i))==0) ok=false;
            }
        }
        if (ok) break;
    }
    fout<<i<<endl;
    return 0;
}
