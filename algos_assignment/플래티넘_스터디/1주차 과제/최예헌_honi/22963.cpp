#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9876543210
typedef long long ll;

ll n;
ll arr[200002];
ll dp[200002][4][2] = {0,};
vector <pair<ll,ll>> result;   // 원래 값, 바뀐 값

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    
    // n이 3보다 작을 때 : 그냥 다 바꿈
    ll temp = 1;
    if (n <= 3){
        for (int i=0; i<n; i++){
            if (arr[i] == temp)
                temp++;
            result.push_back({i+1, temp});
        }
        sort(result.begin(), result.end());
        
        cout<<"YES\n"<<result.size()<<"\n";
        for (int i=0; i<result.size(); i++)
            cout<<result[i].first<<" "<<result[i].second<<"\n";
        return 0;
    }
    
    // dp[0][][] 설정
    dp[0][0][0] = dp[0][1][0] = dp[0][2][0] = dp[0][3][0] = 1;
    
    dp[0][0][1] = arr[0];
    if (arr[0] == 0)
        dp[0][1][1] = 2;
    else
        dp[0][1][1] = 1;
    dp[0][2][1] = dp[0][3][1] = MAX;
    
    // 1~n-1
    for (int i=1; i<n; i++){
        
        for (int k=0; k<4; k++){

            if (k == 0){
                if (dp[i-1][k][0] == 0)
                    dp[i][k][0] = dp[i][k][1] = 0;
                
                else if (arr[i-1] <= arr[i]){
                    dp[i][k][0] = 1;
                    dp[i][k][1] = arr[i];
                }
                
                else
                    dp[i][k][0] = dp[i][k][1] = 0;
            }
            
            else{
                ll a = MAX;
                ll b = MAX;
                
                // 현재 값 바꾸기
                if (dp[i-1][k-1][0] == 0)
                    ;
                else if (arr[i] == dp[i-1][k-1][1] && arr[i] < 1000000000)
                    a = arr[i] + 1;
                else
                    a = dp[i-1][k-1][1];
                
                // 현재 값 그대로
                if (dp[i-1][k][0] == 0)
                    ;
                else if (dp[i-1][k][1] > arr[i])
                    ;
                else
                    b = arr[i];
                
                // 값이 최소인 것 선택
                if (a == MAX && b == MAX)
                    dp[i][k][0] = dp[i][k][1] = 0;
                else{
                    dp[i][k][0] = 1;
                    dp[i][k][1] = min(a, b);
                }
            }
        }
    }
    
    if (dp[n-1][3][0] == 0){
        cout<<"NO";
        return 0;
    }
    
    else{
        ll temp = 3;
        for (ll i = n-1; i>=0; i--){
            if (dp[i][temp][1] != arr[i]){
                result.push_back({i+1, dp[i][temp][1]});
                temp--;
                if (temp == 0)
                    break;
            }
        }
        
        sort(result.begin(), result.end());
        cout<<"YES\n"<<result.size()<<"\n";
        for (int i=0; i<result.size(); i++){
            cout<<result[i].first<<" "<<result[i].second<<"\n";
        }
    }
    
}

/*
 dp[i][k][0] : i번째까지 구간에서 k번 연산 진행 시 오름차순인지 여부
               1이면 가능, 0이면 불가능
 dp[i][k][1] : i번째 값
 */
