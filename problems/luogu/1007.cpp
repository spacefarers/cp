#include <iostream>
#include <set>

using namespace std;

int l, n, min_num, max_num;
set<int> s;

int main(){
    cin>>l>>n;
    if (n==0){
        min_num = 0;
        max_num = 0;
    } else {
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }
        auto first = s.begin();
        auto last = s.end();
        last--;
        max_num = max(l - *first + 1, *last);
        min_num = -0x7fffffff;
        for (auto i : s) {
            min_num = max(min_num, min(i, l - i + 1));
        }
    }
    cout<<min_num<<" "<<max_num<<endl;
}
