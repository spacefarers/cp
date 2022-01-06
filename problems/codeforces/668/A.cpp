#include <iostream>
#include <stack>

using namespace std;

int main() {
    int test_cases;
    cin>>test_cases;
    for (int i=1;i<=test_cases;i++){
        int n;
        stack<int> s;
        cin>>n;
        for (int j=1;j<=n;j++){
            int a;
            cin>>a;
            s.push(a);
        }
        while (!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
}
