//

//  17979.cpp

//  icpc_prac_22

//

//  Created by 최예헌 on 2022/10/10.

//

#include <iostream>

#include <vector>

#include <tuple>

#include <algorithm>

using namespace std;

#define MAX 9876543210

typedef pair<int,int> pii;

int n,m;

int arr[102]={0,};

int a,b,c;

vector<tuple<int,int,int>> v;

int dp[10001]={0,};

int solve(int idx){

    if (idx == n-1)

        return -1*get<2>(v[idx]);

    

    if (dp[idx])

        return dp[idx];

    

    // 현재 범위 포함해서 최대 금액

    int result = 0;

    for (int i=idx+1; i<n; i++){

        if (get<1>(v[idx]) <= get<0>(v[i])){

            result = max(result, solve(i));

        }

    }

    result += (-1*get<2>(v[idx]));

    

    // 현재 범위 포함 안했을 때 최대 금액

    dp[idx] = max(result, solve(idx+1));

    return dp[idx];

}

int main() {

    cin.tie(0); cout.tie(0);

    ios::sync_with_stdio(false);

    

    cin>>m>>n;

    for (int i=1;i<=m;i++)

        cin>>arr[i];

    

    for (int i=0;i<n;i++){

        cin>>a>>b>>c;

        int cost = (b-a)*arr[c];

        v.push_back({a, b, -1*cost});

    }

    sort(v.begin(), v.end());

    

    cout<<solve(0);

    return 0;

}
