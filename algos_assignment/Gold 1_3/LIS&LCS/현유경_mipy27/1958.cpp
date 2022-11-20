#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int dp[MAX][MAX][MAX]; //dp 3차원 배열

int max(int a, int b, int c) { // 인자가 3개인 최대값 함수
    return max(max(a, b), c);
}

int main() {
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    
    str1 = ' ' + str1;
    str2 = ' ' + str2;
    str3 = ' ' + str3;
    
    for(int i=1;i<str1.size();i++) {
        for(int j=1;j<str2.size();j++) {
            for(int k=1;k<str3.size();k++) {
                
                if(str1[i] == str2[j] && str2[j] == str3[k]) { // 문자가 모두 같은 경우
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else { // 같지 않은 경우
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]); // 최대값 저장
                }
            }
        }
    }
    cout << dp[str1.size()-1][str2.size()-1][str3.size()-1];
}
