#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 321
#define INF 987654321

vector <int> v[MAX];
int cap[MAX][MAX] = {0,};   // 용량
int flow[MAX][MAX] = {0,};  // 현재 유량
int pre[MAX];               // 경로를 기억하는 역할

int maxFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    
    while (1){
        queue<int> q;
        memset(pre, -1, sizeof(pre));
        
        q.push(source);
        pre[source] = source;
        
        while (!q.empty()){
            int now = q.front();
            q.pop();
            
            if (now == sink)
                break;
            
            for (int i = 0; i < v[now].size(); i++){
                int next = v[now][i];
                
                // 방문하지 않은 정점 중 용량이 남는 경우
                if (cap[now][next] - flow[now][next] > 0 && pre[next] == -1){
                    q.push(next);
                    pre[next] = now;
                }
            }
        }
        
        // 더 이상 증가 경로 없음
        if (pre[sink] == -1)
            break;
        
        // 증가 경로로 새로 흘려줄 유량 = 경로 중 최소 잔여 용량
        int minFlow = INF;
        for (int i = sink; i != source; i = pre[i]){
            int j = pre[i];
            minFlow = min(cap[j][i] - flow[j][i], minFlow);
        }
        
        // 증가 경로는 유량 증가, 역방향 경로는 유량 감소
        for (int i = sink; i != source; i = pre[i]){
            int j = pre[i];
            flow[j][i] += minFlow;
            flow[i][j] -= minFlow;
        }
        totalFlow += minFlow;
    }
    return totalFlow;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, K, D;
    int foodCnt, foodNum;
    int source = 301, sink = 302;
    int bias = 200;
        
    cin >> N >> K >> D;
    for (int i = 1; i <= D; i++){
        cin >> cap[bias+i][sink];
        v[sink].push_back(bias+i);
        v[bias+i].push_back(sink);
    }
    
    for (int i = 1; i <= N; i++){
        cin >> foodCnt;
        cap[source][i] = K;
        v[source].push_back(i);
        v[i].push_back(source);
            
        while (foodCnt--){
            cin >> foodNum;
            cap[i][bias+foodNum] = 1;
            v[i].push_back(bias+foodNum);
            v[bias+foodNum].push_back(i);
        }
    }
    cout << maxFlow(source, sink);
    return 0;
}
