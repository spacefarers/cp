#include <iostream>

using namespace std;

long long S(long long n, bool single = false) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool is_rabbit(long long n) {
    return S(n*n) == S(n)*S(n);
}

int main() {
    long long l, r;
    cin >> l >> r;
    int c = 0;
//    cout<<"ha";
    for (int a1 = 0; a1 <= 3; a1++)
        for (int a2 = 0; a2 <= 3; a2++)
            for (int a3 = 0; a3 <= 3; a3++)
                for (int a4 = 0; a4 <= 3; a4++)
                    for (int a5 = 0; a5 <= 3; a5++)
                        for (int a6 = 0; a6 <= 3; a6++)
                            for (int a7 = 0; a7 <= 3; a7++)
                                for (int a8 = 0; a8 <= 3; a8++)
                                    for (int a9 = 0; a9 <= 3; a9++)
                                        for (int a10 = 0; a10 <= 3; a10++) {
                                            int current_num =
                                                    a1 * 1e8 + a2 * 1e7 + a3 * 1e6 + a4 * 1e5 + a5 * 1e4 + a6 * 1e3 +
                                                    a7 * 1e2 + a8 * 10 + a9 + a10 * 1e9;
                                            if (current_num < l || current_num > r) continue;
                                            if (is_rabbit(current_num)){c++;}
                                        }
    cout << c;
//    cout<<S(5);
    return 0;
}
