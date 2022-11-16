#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 100005
#define INF 987654321

int n, m;
int dp[MAX][2] = {0,};
vector <int> v[MAX];
vector <pair<int,int>> arr;

void solve(int node){
    
    for (int i=0; i<v[node].size(); i++){
        
        int child = v[node][i];
        if (dp[child][0] < dp[node][0]){
//            cout<<"*";
            if (dp[node][1] + 1 > dp[child][1]){
                dp[child][1] = dp[node][1] + 1;
                solve(child);
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a, b;
    
    cin>>n>>m;
    for (int i=0; i<m; i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int minx = INF;
    for (int i=0; i<n; i++){
        arr.push_back({-v[i].size(), i});
        dp[i][0] = v[i].size();
        dp[i][1] = 1;
        minx = min(minx, dp[i][0]);
    }
    sort(arr.begin(), arr.end());
    
    
    for (int i=0; i<arr.size(); i++){
        if (-arr[i].first <= minx)
            break;
        solve(arr[i].second);
    }
    
    int result = 0;
    for (int i=0; i<n; i++)
        result = max(result, dp[i][1]);
    
    cout<<result;
}
