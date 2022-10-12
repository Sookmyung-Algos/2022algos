//
//  11054.cpp
//  prac_22
//
//  Created by 최예헌 on 2022/10/10.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 9876543210
typedef pair<int,int> pii;


int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    int arr[1002]={0,};
    int dp1[1002] = {0,};
    int dp2[1002] = {0,};
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for (int i=0;i<n;i++){
        dp1[i] = 1;
        for (int j=0;j<=i;j++){
            if (arr[j] < arr[i] && dp1[i] < dp1[j]+1){
                dp1[i] = dp1[j] + 1;
            }
        }
    }
    
    for (int i=n-1;i>=0;i--){
        dp2[i] = 1;
        for (int j=n-1; j>=i; j--){
            if (arr[i] > arr[j] && dp2[j]+1 > dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }
    }
    
    int result = 0;
    for (int i=0;i<n;i++){
        result = max(result, dp1[i] + dp2[i]-1);
    }
    cout<<result;
}

