#include <iostream>
using namespace std;

int n, m;
long long result = 0;
int arr[100001];

int main() {
    int i;
    long long sum = 0;

    cin >> n >> m;

    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for (i = 1; i <= n; i++) {
        if (i > m) {
            sum -= arr[i - m];
        }

        sum += arr[i];
        result = max(result, sum);
    }

    cout << result;
    
    return 0;
}
