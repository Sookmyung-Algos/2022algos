#include <iostream>
using namespace std;
const int n_ = 2200;

int arr[n_][n_];
int ans[3];

void f(int y, int x, int n) {
    if (n == 1) {
        ans[arr[y][x] + 1]++;
        return;
    }
    
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (arr[y][x] != arr[i][j]) { // 2
                n /= 3;
                f(y, x, n);
                f(y + n, x, n);
                f(y + 2*n, x, n);
                f(y, x + n, n);
                f(y + n, x + n, n);
                f(y + 2*n, x + n, n);
                f(y, x + 2*n, n);
                f(y + n, x + 2*n, n);
                f(y + 2*n, x + 2*n, n);
                return;
            }
        }
    }
    ans[arr[y][x] + 1]++; // 1
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    f(0, 0, n);
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
    return 0;
}
