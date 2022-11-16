//knapsack dp
//k개의 물건 준비되어 있는 것 = 1개짜리 패키지, 2개짜리 패키지,..., 2^m개 크기 패키지, k+1-2^(m+1) 크기 패키지
//1,2,4,8,..개 챙기는 경우만 고려함.

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    int v,c,k;
    int dp[10005];
    
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        int temp=1;
        
        cin>>v>>c>>k;
        while (k>0){
            if (k<temp)
                temp=1;
            
            for (int j=m; j>=v*temp;j--){
                dp[j] = max(dp[j],dp[j-v*temp] + c*temp);
            }
            k-=temp;
            temp*=2;
        }
    }
    cout<<dp[m];
}
