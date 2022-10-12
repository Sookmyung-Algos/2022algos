//
//  1640.cpp
//  icpc_prac_22
//
//  Created by 최예헌 on 2022/10/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;
    int dp[2][1002]={0,};       // [0]: i, [1]: j
    int cntn=0, cntm=0;
    string x;
    
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x;
        for (int j=0;j<m;j++){
            if (x[j] == '1'){
                dp[0][i]++;
                dp[1][j]++;
            }
        }
    }
    
    for (int i=0;i<n;i++){
        if (dp[0][i]%2 == 0)
            cntn++;
    }
    
    for (int j=0;j<m;j++){
        if (dp[1][j]%2 == 0)
            cntm++;
    }
    
    int result = -1;
    // 둘 다 짝수인 경우
    if (cntn == n && cntm == m){
        result = 0;
    }
    // 둘 다 홀수인 경우
    else if (cntn == 0 && cntm == 0){
        result = min(n,m);
    }
    
    else{
        // 한 쪽 짝수로 다 만들기
        if ((n-cntn) % 2 == 0){     // 바꿔야할 홀수가 짝수개 있는 경우
            if ((m-cntm) % 2 == 0){
                if (result == -1)
                    result = (n-cntn)+(m-cntm);
                
                result = min(result, (n-cntn)+(m-cntm));
            }
        }
        else{
            if (cntm % 2 == 0){
                if (result == -1)
                    result = (n-cntn)+cntm;
                
                result = min(result, (n-cntn)+cntm);
            }
        }
        
        // 한 쪽 홀수로 다 만들기
        if (cntn % 2 == 0){         // 바꿔야할 짝수가 짝수개 있는 경우
            if ((m-cntm) % 2 != 0){
                if (result == -1)
                    result = cntn+(m-cntm);
                
                result = min(result, cntn+(m-cntm));
            }
        }
        else{
            if (cntm%2 != 0){
                if (result == -1)
                    result = cntn+cntm;
                
                result = min(result, cntn+cntm);
            }
        }
    }
    cout<<result;
}
