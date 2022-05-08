#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    long long temp, sum[100001];
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> k;
        sum[i] = sum[i-1] + k;
    }
    
    long long result = 0;
    
    for (int i = m; i <= n; i++) {
        temp = sum[i] - sum[i-m];
        
        result = max(result, temp);
    }
    
    cout << result << "\n";
    
    return 0;
}

