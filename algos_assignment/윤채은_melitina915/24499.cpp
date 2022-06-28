#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K,ans = 0; cin>>N>>K;
    
    vector<int>arr, dp(2*N);
    
    
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        arr.push_back(inp);
    }
    
    for(int i=0; i<N; i++){
        arr.push_back(arr[i]);
    }
    
    dp[0] = arr[0];
    for(int i=1; i<K; i++){
        dp[i]=dp[i-1]+arr[i];
    }
    
    for(int i=K; i<2*N; i++){
        dp[i]=dp[i-1]-arr[i-K]+arr[i];
        ans = max(ans, dp[i]);
    }
    
    cout<<ans;
    
}
