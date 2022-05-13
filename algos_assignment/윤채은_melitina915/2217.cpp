#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, i, min = 0, rope[100001] = {};

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> rope[i];
    }

    sort(rope, rope + n);

    for (i = 0; i < n; i++) {
        if (rope[i] * (n - i) > min) {
            min = rope[i] * (n - i);
        }
    }
    cout << min;
}
