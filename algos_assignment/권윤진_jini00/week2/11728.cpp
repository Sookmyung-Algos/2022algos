#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> a(N), b(M), arr(N+M);
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int a_idx = 0, b_idx = 0, idx = 0;
    
    while (a_idx < N && b_idx < M) {
        if (a[a_idx] > b[b_idx])
            arr[idx++] = b[b_idx++];
        
        else
            arr[idx++] = a[a_idx++];
    }
    
    while (a_idx < N)
        arr[idx++] = a[a_idx++];
        
    while (b_idx < M)
        arr[idx++] = b[b_idx++];
    
    for (int i = 0; i < N + M; i++) {
        cout << arr[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
