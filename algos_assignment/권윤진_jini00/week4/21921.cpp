#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, X, sum = 0;
    int visit[250000];
    
    cin >> N >> X;
    
    for (int i = 0; i < X; i++) {
        cin >> visit[i];
        sum += visit[i];
    }
    
    int cnt = 1;
    int result = sum;
    
    for (int i = X; i < N; i++) {
        cin >> visit[i];
        sum += visit[i] - visit[i-X];
        if (sum >= result) {
            if (sum == result) {
                cnt++;
            }
            else {
                result = sum;
                cnt = 1;
            }
        }
    }
    
    if (result == 0)
        cout << "SAD" << "\n";
    else
        cout << result << "\n" << cnt << "\n";
    
    return 0;
}
