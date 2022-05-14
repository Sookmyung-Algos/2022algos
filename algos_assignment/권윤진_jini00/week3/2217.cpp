#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N, result = 0, sum = 0;

    cin >> N;
    
    vector<int> rope(N);
    
    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    
    sort(rope.begin(), rope.end(), greater<int>());
 
    for (int i = 0; i < N; i++) {
        sum = rope[i] * (i + 1);
        
        if (sum > result)
            result = sum;
    }
    
    cout << result << "\n";
 
    return 0;
}
