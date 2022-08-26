#include <iostream>
using namespace std;

void f(int n, int k, int len) {
    int curLen = 2 * len + (k + 3);
    
    if (n <= 3) {
        if (n == 1) cout << "m";
        else cout << "o";
        exit(0);
    }
    
    if (curLen < n) f(n, k+1, curLen);
    else {
        if (len < n && n <= len + k + 3) {
            if (n == len + 1) cout << "m";
            else cout << "o";
            exit(0);
        }
        else f(n - (len + k + 3), 1, 3);
    }
}

int main()
{
    int n; cin >> n;
    f(n, 1, 3);
    return 0;
}
