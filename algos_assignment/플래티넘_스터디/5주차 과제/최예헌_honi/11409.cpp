#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> tii;
#define MAX 805
#define INF 987654321

vector <int> v[MAX];
int cap[MAX][MAX] = {0,};   // 용량
int flow[MAX][MAX] = {0,};  // 현재 유량
int pre[MAX];               // 경로를 기억하는 역할
int cost[MAX][MAX];         // 노드에서 노드로 이동하는데 필요한 비용
int dist[MAX];              // source 노드에서 해당 번호의 노드로 이동하는데 필요한 비용

int costCnt = 0;         
int costSum = 0;

void mcmf(int source, int sink){
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    
    while (1){
        queue<int> q;
        bool isInQ[MAX];
        
        memset(pre, -1, sizeof(pre));
        memset(isInQ, false, sizeof(isInQ));
        
        // cost 배열 초기화
        for (int i=0; i<MAX; i++)
            dist[i] = INF;
        
        q.push(source);
        pre[source] = source;
        dist[source] = 0;
        isInQ[source] = true;
        
        while (!q.empty()){
            int now = q.front();
            q.pop();
            isInQ[now] = false;
            
//            if (now == sink)
//                break;
            
            for (int i = 0; i < v[now].size(); i++){
                int next = v[now][i];
                
                // 방문하지 않은 정점 중 용량이 남는 경우
                if (cap[now][next] - flow[now][next] > 0 && dist[now] + cost[now][next] < dist[next]){
                    pre[next] = now;
                    dist[next] = dist[now] + cost[now][next];
                    
                    if (!isInQ[next]){
                        q.push(next);
                        isInQ[next] = true;
                    }
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
            costSum += minFlow * cost[j][i];
        }
        totalFlow += minFlow;
        costCnt++;
    }
    return;
}


int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    int workCnt, workNum, pay;
    int source = 801, sink = 802;
    int bias = 400;
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> workCnt;
        v[source].push_back(i);
        v[i].push_back(source);
        cap[source][i] = 1;
        
        while (workCnt--){
            cin >> workNum >> pay;
            v[i].push_back(bias+workNum);
            v[bias+workNum].push_back(i);
            cost[i][bias+workNum] = -pay;
            cost[bias+workNum][i] = pay;
            cap[i][bias+workNum] = 1;
        }
    }
    
    for (int i = 1; i <= M; i++){
        v[sink].push_back(bias+i);
        v[bias+i].push_back(sink);
        cap[bias+i][sink] = 1;
    }
    
    mcmf(source, sink);
    cout<<costCnt<<" "<<-costSum;
    return 0;
}
