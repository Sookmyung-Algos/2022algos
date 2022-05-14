#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> money;

bool check(int n) {
    int cnt = 1;
    int temp = n;
    
    for (int i = 0; i < N; i++) {
        if (money[i] <= n)
            n -= money[i];
        else {
            n = temp;
            cnt++;
            
            if (money[i] > n)
                return false;
            
            n -= money[i];
        }
    }
    return cnt <= M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> num;
        money.push_back(num);
    }
    
    int left = 1;
    int right = 10000;
    int result = 0, mid = 0;
    
    while (left <= right) {
        mid = (left + right) / 2;
        
        if (check(mid)) {
            right = mid - 1;
            result = mid;
        }
        
        else {
            left = mid + 1;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
