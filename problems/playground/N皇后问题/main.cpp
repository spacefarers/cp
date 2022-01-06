#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> temp_sol;
vector<bool> cols;
vector<bool> diag_1;
vector<bool> diag_2;
int c;


void update_board(int x, int y, int n, bool is_put) {
    cols[x] = is_put;
    diag_1[x + y] = is_put;
    diag_2[x - y + n - 1] = is_put;
    if (is_put && c < 3) {
        temp_sol[y] = x;
    }
}

bool is_square_available(int x, int y, int n) {
    return !cols[x] && !diag_1[x + y] && !diag_2[x - y + n - 1];
}


void find(const int n, const int y) {
    if (y == n) {
        if (c < 3) {
            for (int i : temp_sol) {
                cout << i + 1 << " ";
            }
            cout << endl;
        }
        c++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!is_square_available(i, y, n)) continue;
//        cout<<i<<" "<<y<<endl;
        update_board(i, y, n, true);
        find(n, y + 1);
        update_board(i, y, n, false);
    }

}

int main() {
    int n;
    cin >> n;
    cols = vector<bool>(n, false);
    diag_1 = vector<bool>(2 * n - 1, false);
    diag_2 = vector<bool>(2 * n - 1, false);
    temp_sol = vector<int>(n, 0);
    c = 0;
    find(n, 0);
    cout << c;
    return 0;
}

