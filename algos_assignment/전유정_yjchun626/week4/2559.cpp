#include <iostream>

using namespace std;
 
const int MAX = 100001;
 
int arr[MAX];
long long int res;
 
int main() {
 
    int n, k;
    cin >> n >> k;
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int s = 0;
    long long int sum = 0;
    for (int i = s; i < s + k; i++) {
        sum += arr[i];
    }
    res = sum;
 
    //탐색
    while (true) {
        sum -= arr[s];
        if (s+k >= n) {
            break;
        }

        sum += arr[s+k];
        if (sum > res) {
            res = sum;
        }

        s++;
    }
 
    cout << res;
}
