#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long* tree = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    long long high = 1000000000;
    long long low = 0;
    long long mid;
    long long tcut;
    long long answer = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        tcut = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                tcut = tcut + (tree[i] - mid);
            }
        }
        if (tcut == m) {
            answer = mid;
            break;
        }
        else if (tcut > m) {
            if (answer < mid) {
                answer = mid;
            }
            low = mid + 1;
        }
        else if (tcut < m) {
            high = mid - 1;
        }
    }
    cout << answer;
    delete[] tree;
    return 0;
}
