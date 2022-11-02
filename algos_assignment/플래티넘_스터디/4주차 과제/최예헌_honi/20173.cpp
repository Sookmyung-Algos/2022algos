#include <iostream>

#include <cmath>

using namespace std;

int n,x;

bool dp[1000002][2][2] = {0,};        // [n][round1][round2]

int dx[4] = {0,0,1,1};

int dy[4] = {0,1,0,1};

bool check = false;

int num1, num2;

void solve(int num1, int num2, int x, int i){

    for (int k=0;k<4;k++){

        int nn1 = num1+dx[k];

        int nn2 = num2+dy[k];

        

        if (abs(nn1-nn2) == x){

            dp[i][dx[k]][dy[k]] = true;

            check = true;

        }

    }

    return;

}

int main(){

    cin.tie(0); cout.tie(0);

    ios::sync_with_stdio(false);

    

    cin>>n;

    

    for (int i=1;i<=n;i++){

        cin>>x;

        

        // 1 or n : 1 이하 // 중간 : 2 이하

        if (i == 1 || i == n){

            if (x >= 2){

                cout<<"NO";

                return 0;

            }

        }

        else {

            if (x >= 3){

                cout<<"NO";

                return 0;

            }

        }

        

        // ===========================

        if (i == 1){

            if (x == 0){

                dp[1][0][0] = true;

                dp[1][1][1] = true;

            }

            else if (x == 1){

                dp[1][1][0] = true;

                dp[1][0][1] = true;

            }

        }

        

        else if (i == n){

            check = false;

            

            for (int k=0;k<4;k++){

                num1 = 0; num2 = 0;

                

                if (dp[i-1][dx[k]][dy[k]]){

                    num1 += (abs(dx[k]-1));

                    num2 += (abs(dy[k]-1));

                    

                    if (abs(num1-num2) == x)

                        check = true;

                }

            }

            

            if (!check){

                cout<<"NO";

                return 0;

            }

        }

        

        else{

            check = false;

            

            for (int k=0;k<4;k++){

                num1 = 0; num2 = 0;

                

                if (dp[i-1][dx[k]][dy[k]]){

                    num1 += (abs(dx[k]-1));

                    num2 += (abs(dy[k]-1));

                    solve(num1, num2, x, i);

                }

            }

            

            if (!check){

                cout<<"NO";

                return 0;

            }

        }

    }

    cout<<"YES";

    return 0;

}

