#include<iostream>
#include<algorithm>
using namespace std;
 
 
int main() {
    int N, M, lo = 0;
    cin >> N >> M;
    int arr[100001];
    int hi = 0;
 
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi = hi + arr[i];
    }
 
    int mid = 0;
 
    //이분 탐색
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int cnt = 1;
        int money = mid;
        for (int i = 0; i < N; i++) {
            money = money - arr[i];
            if (money <= 0) {
                money = mid - arr[i];
                cnt++;
            }
        }
 
        if (cnt > M) lo = mid + 1;
        else
            hi = mid - 1;
 
    }
 
    cout << mid;
 
}
