/*
ID: michael419
LANG: C++
TASK: moobuzz
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("moobuzz.out");
    ifstream fin ("moobuzz.in");
    long long n, a, b;
    fin>>n;
    a = n/8;
    b = n%8;
    switch (b) {
        case 3:
            b=4;
            break;
        case 4:
            b=7;
            break;
        case 5:
            b=8;
            break;
        case 6:
            b=11;
            break;
        case 7:
            b=13;
            break;
        case 0:
            b=-1;
            break;
    }
    fout<<a*15+b<<endl;
    return 0;
}