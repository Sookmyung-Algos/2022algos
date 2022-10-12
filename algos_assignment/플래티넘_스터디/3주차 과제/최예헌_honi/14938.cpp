//
//  1238.cpp
//  icpc_prac_22
//
//  Created by 최예헌 on 2022/10/10.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 9876543210
typedef pair<int,int> pii;

int n,m,r;
int arr[102]={0,};
vector <pair<int,int>> v[102];
int dijk[102]={0,};
bool visited[102];
int result = 0;

void solve(int node){
    for (int i=0;i<=n;i++)
        dijk[i] = MAX;
    
    for (int i=0;i<=n;i++)
        visited[i] = false;
    
    priority_queue <pii, vector<pii>, greater<pii>> q;
    dijk[node] = 0;
    q.push({0,node});
    
    while (!q.empty()){
        int w = q.top().first;
        int n = q.top().second;
        q.pop();
        
        if (visited[n])
            continue;
        
        visited[n] = true;
        for (int i=0;i<v[n].size();i++){
            int nextn = v[n][i].first;
            int nextw = v[n][i].second;
            
            if (dijk[nextn] > w+nextw && !visited[nextn]){
                dijk[nextn] = w+nextw;
                q.push({dijk[nextn], nextn});
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int a,b,c;
    cin>>n>>m>>r;
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    
    for (int i=0;i<r;i++){
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    for (int i=1; i<=n; i++){
        solve(i);
        
        int sum = 0;
        for (int j=1;j<=n;j++){
            if (dijk[j] <= m)
                sum+=arr[j];
        }
        result = max(result, sum);
    }
    cout<<result;
}
