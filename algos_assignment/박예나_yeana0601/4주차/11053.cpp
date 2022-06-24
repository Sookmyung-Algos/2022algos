#include <stdio.h>

int arr[1005];
int dp[1005];

int main(){
    int n;
    int ans = 0;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<=dp[j]){
                dp[i] = dp[j]+1;
                if(dp[i]>ans) ans = dp[i];
            }
        }
    }

    printf("%d",ans);

    return 0;
}
