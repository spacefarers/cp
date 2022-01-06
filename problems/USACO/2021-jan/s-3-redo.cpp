#include <iostream>

using namespace std;

int value[1005][1005];

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>value[i][j];
        }
    }
    int ans1=0, ans2=0;
    for (int i=0;i<n;i++){
        int c_ans1=0, c_ans2=0, c_ans3=0, c_ans4=0;
        for (int j=0;j<n;j++){
            if (j%2) {
                c_ans1+=value[i][j];
                c_ans3+=value[j][i];
            } else {
                c_ans2+=value[i][j];
                c_ans4+=value[j][i];
            }
        }
        ans1+=max(c_ans1, c_ans2);
        ans2+=max(c_ans3, c_ans4);
    }
    cout<<max(ans1, ans2)<<endl;
}