#include <iostream>

using namespace std; 

int n, m, arr[100001];
long long result, sum = 0;

int main() {
    
    cin >> n >> m; 

    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; 
    }

    for (int i = 1; i <= n; i++) {
        if (i > m) {
            sum -= arr[i - m]; 
        }
        sum += arr[i];
        result = max(result, sum); 
    }

    cout << result; 
}
