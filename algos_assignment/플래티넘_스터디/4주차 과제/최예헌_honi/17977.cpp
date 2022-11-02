//

//  17977.cpp

//  icpc_prac_22

//

//  Created by 최예헌 on 2022/10/10.

//

#include <iostream>

#include <vector>

#include <set>

using namespace std;

#define MAX 9876543210

typedef pair<int,int> pii;

int main() {

    cin.tie(0); cout.tie(0);

    ios::sync_with_stdio(false);

    

    int n;

    int dp[1000002]={0,};

    

    cin>>n;

    dp[3]=0;

    dp[4]=1;

    if (n<5)

        cout<<dp[n];

    else{

        for (int i=5;i<=n;i++){

            dp[i] = 2+dp[(i+1)/2];

        }

        cout<<dp[n];

    }

    return 0;

}
