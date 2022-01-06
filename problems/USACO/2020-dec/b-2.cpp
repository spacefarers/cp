#include <iostream>
#include <vector>

using namespace std;

vector<int> flowers;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        flowers.push_back(a);
    }
    int ans=n;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            double avg=0;
            for (int k=i;k<=j;k++){
                avg+=flowers[k];
            }
            avg/=(j-i+1);
            bool ok=false;
            for (int k=i;k<=j;k++){
                if (flowers[k]==avg) ok=true;
            }
            if (ok) ans++;
        }
    }
    cout<<ans<<endl;
}