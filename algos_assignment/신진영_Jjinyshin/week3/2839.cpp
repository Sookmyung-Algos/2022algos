#include <iostream>

using namespace std;

int main()
{
    int N, tmp, m = 0;

    cin >> N;

    if (N % 5 == 0) {
        cout << N / 5 << endl;
        return 0;
    }

    tmp = N / 5;
    while (tmp >= 0) {
        if ((N - 5 * tmp) % 3 == 0) {
            m = tmp + (N - 5 * tmp) / 3;
            cout << m << endl;
            return 0;
        }
        tmp--;
    }
    cout << -1 << endl;
    return 0;

}
