#include <iostream>
#include <vector>

using namespace std;

int best_ans, n;

void dfs(int* working_arr, int* mapped){
    bool ok=false;
    for (int i=1;i<n;i++){
        if (mapped[i]<0 || working_arr[i] == working_arr[mapped[i]]) continue;
        //cout<<working_arr[i]<<" "<<working_arr[mapped[i]]<<endl;
        ok=true;
        working_arr[i] += working_arr[mapped[i]];
        int rest1 = mapped[i];
        //cout<<i<<endl;
        mapped[i] = mapped[mapped[i]];
        int rest = mapped[rest1];
        mapped[rest1] = -100;
        dfs(working_arr, mapped);
        mapped[rest1] = rest;
        mapped[i] = rest1;
        working_arr[i] -= working_arr[mapped[i]];
    }
    if (!ok){
        int ans=0;
        for (int i=0;i<n;i++){
            if (mapped[i]!=-100) ans++;
            //cout<<mapped[i]<<" ";
        }
        //cout<<endl;
        if (ans<best_ans) best_ans = ans;
    }
}

int main(){
    int test_cases;
    cin>>test_cases;
    for (int test_case=0;test_case<test_cases;test_case++){
        cin>>n;
        best_ans = 0x7fffffff;
        int* working_arr = new int[n];
        int* mapped = new int[n];
        for (int i=0;i<n;i++){
            cin>>working_arr[i];
            mapped[i] = i-1;
        }
        dfs(working_arr, mapped);
        cout<<best_ans<<endl;
    }
}
