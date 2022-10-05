#include <iostream>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int t, k;
    int arr[505];
    int sum[505];
    int dp[505][505];
    
    cin>>t;
    while (t--){
        cin>>k;
        for (int i=1; i<=k; i++){
            cin>>arr[i];
            sum[i]=sum[i-1]+arr[i];
        }
        
        for (int i=1;i<=k;i++){
            for (int j=1; j<= k-i; j++){
                dp[j][i+j] = 9876543210;
                for (int p=j; p<i+j;p++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][p]+dp[p+1][i+j] + sum[i+j]-sum[j-1]);
                }
            }
        }
        cout<<dp[1][k]<<"\n";
    }
}
