//
//  20171.cpp
//  icpc_prac_22
//
//  Created by 최예헌 on 2022/10/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;

int n,m;
int a,b,c,x;
vector <int> v[100002];
set <int> s;
int dp[100002]={0,};
int result = 1;

int solve(int parent, int node){
    if (v[node].size() == 1 && v[node][0] == parent){
        if (s.find(node) != s.end()){
            dp[node]=1;
        }
        else
            dp[node]=0;
    }
    
    else{
        if (s.find(node) != s.end())
            dp[node]=1;
        
        for (int i=0;i<v[node].size();i++){
            if (v[node][i] == parent)
                continue;
            
            dp[node] += solve(node, v[node][i]);
        }
    }
    return dp[node];
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    
    v[1].push_back(0);
    for (int i=0;i<n-1;i++){
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i=0;i<m;i++){
        cin>>x;
        s.insert(x);
    }
    
    solve(0,1);
    for (int i=1;i<=n;i++){
        if (dp[i] > 0 && dp[i] < m){
            result++;
        }
    }
    cout<<result;
}
