#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[110][10010];

vector<int> memory;
vector<int> cost;

int main(){
    int n, m;
    int sum = 0;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        memory.push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        cost.push_back(a);
        sum += a;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if( j - cost[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i-1]] + memory[i-1]);
            }
            
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    
    for(int i = 0; i <= sum; i++){
        if(dp[n][i] >= m){
            cout << i;
            return 0;
        }
    }
    
}
