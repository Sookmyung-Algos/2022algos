#include <iostream>
#include <vector>
#define MAX 101
#define INF 1e9

using namespace std;

int dp[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> v(n+1);
    
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=INF;
        }
    }
    
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int z = j/v[i].second; z >= 0; z--) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - z * v[i].second] + (v[i].first * z) + (k * ((z * (z - 1)) / 2)));
            }
        }
    }
    
    cout<<dp[n][m];
    return 0;
}
