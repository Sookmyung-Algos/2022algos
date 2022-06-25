#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    int* ropes = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    sort(ropes, ropes + n, desc);

    int max = ropes[n - 1] * n;
    for (int i = n - 1; i > 0; i--) {
        if (ropes[i - 1] * i > max) max = ropes[i - 1] * i;
    }

    cout << max << endl;

    delete[] ropes;
}
