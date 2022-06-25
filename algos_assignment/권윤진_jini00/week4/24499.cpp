#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N, K, result = 0;
    cin >> N >> K;
    
    vector<int> v, dp(2*N);
    
    for(int i = 0; i < N; i++){
        int taste;
        cin >> taste;
        v.push_back(taste);
    }
    
    for(int i = 0; i < N; i++){
        v.push_back(v[i]);
    }
    
    dp[0] = v[0];
    for(int i = 1; i < K; i++){
        dp[i] = dp[i-1] + v[i];
    }
    
    for(int i = K; i < 2*N; i++){
        dp[i] = dp[i-1] - v[i-K] + v[i];
        result = max(result, dp[i]);
    }
    
    cout << result << "\n";
    
    return 0;
}
