#include <iostream>
#include <vector>

using namespace std;

vector<int> bales;
int n, mins1[50005], mins2[50005];

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        double a;
        cin>>a;
        bales.push_back(a);
    }
    sort(bales.begin(), bales.end());
    for (int i=1;i<n;i++){
        int j=i-1;
        while (j>=0&&mins1[j]<=bales[i]-bales[j]-1) j--;
        mins1[j]=bales[i]-bales[j];
    }
}