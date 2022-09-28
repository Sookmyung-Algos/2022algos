#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll arr[1002];
ll dp[1002][1002];

ll solve(ll a, ll b, ll turn){
    if (dp[a][b] != 0){
        return dp[a][b];
    }
    
    if (a == b){
        if (turn == 0){
            dp[a][b] = arr[a];
        }
        return dp[a][b];
    }

    if (turn == 0){     // 근우
        dp[a][b] = max(arr[a]+solve(a+1, b, 1), arr[b] + solve(a, b-1, 1));
    }
    
    else if (turn == 1){     // 명우
        dp[a][b] = min(solve(a+1, b, 0), solve(a, b-1, 0));
    }
    return dp[a][b];
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int t, n;
    cin>>t;
    
    while (t--){
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>arr[i];
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                dp[i][j] = 0;
            }
        }
        solve(0, n-1, 0);
        cout<<dp[0][n-1]<<"\n";
    }
}
