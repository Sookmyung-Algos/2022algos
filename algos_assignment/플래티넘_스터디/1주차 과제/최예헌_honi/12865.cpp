#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n,k,w,v;
vector <pair<ll,ll>> arr;
ll dp[102][100002];

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>w>>v;
        arr.push_back({w,v});
    }
    
    for (int i=0;i<=n;i++){
        dp[i][0] = dp[0][i] = 0;
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            ll wi = arr[i-1].first;
            ll vi = arr[i-1].second;
            
            // i번째 물체의 무게를 포함할 수 없는 경우
            if (wi > j){
                dp[i][j] = dp[i-1][j];
            }
            // i번째 물체의 무게를 배낭의 용량(k)가 포함할 수 있는 경우
            else{
                dp[i][j] = max(dp[i-1][j], vi+dp[i-1][j-wi]);
            }
        }
    }
    cout<<dp[n][k];
}
