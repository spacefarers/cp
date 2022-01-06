/*
ID: michael419
LANG: C++
TASK: gymnastics
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n, m, ans=0;
    ofstream fout ("gymnastics.out");
    ifstream fin ("gymnastics.in");
    fin>>n>>m;
    int inputs[n][m];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            fin>>inputs[i][j];
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            if (i==j)continue;
            bool valid=true;
            for (int k=0;k<n;k++){
                for (int a=0;a<m;a++){
                    if (inputs[k][a]-1 == i) break;
                    else if (inputs[k][a]-1 == j) {
                        valid=false;
                        break;
                    }
                }
                if (!valid) break;
            }
            if (valid) ans++;
        }
    }
    fout<<ans<<endl;
    return 0;
}
