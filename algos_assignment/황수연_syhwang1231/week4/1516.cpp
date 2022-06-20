#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

using namespace std;

int N;  // N: 건물 종류의 수
int times[MAX];  // 각 빌딩 짓는데 걸리는 시간
int dp[MAX];  // 이전에 지어져야 하는 빌딩 고려한 총 시간, final result
int ancestors[MAX];
vector<vector<int>> buildings;  // buildings[i]: i번째 건설을 필요로 하는 빌딩들

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    buildings.resize(N+1);
    
    for(int i=1; i<=N; i++){
        int c;
        cin >> c;  // c: i번째 짓는데 걸리는 시간 
        times[i] = c;
        
        while(true){
            int node;
            cin >> node;
            if(node == -1)
                break;
            else{
                buildings[node].push_back(i);
                ancestors[i]++;
            }
        }
    }
    
    queue<int> q;
    for(int i=1; i<=N; i++){  // 선행적으로 지어져야 하는 빌딩 없는 빌딩들 처리
        if(ancestors[i] == 0){
            q.push(i);
            dp[i] = times[i];
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<buildings[cur].size();i++){  // cur번 빌딩의 건설을 필요로 하는 빌딩들에 대해
            int next = buildings[cur][i];
            ancestors[next]--;
            
            dp[next] = max(dp[next], dp[cur]+times[next]);  // 더 오래 걸리는 시간으로
            if(ancestors[next] == 0)
                q.push(next);
        }
    }
    
    for(int i=1;i<=N;i++)
        cout << dp[i] << "\n";
    
    return 0;
}
