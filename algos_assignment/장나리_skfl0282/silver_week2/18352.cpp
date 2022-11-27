#include <vector>
#include <iostream>
#include <queue>

#define MAX 300001        // 최대 정점의 개수 
#define INF 1e9

using namespace std;

vector<int> dijkstra(int k, int V, vector<vector<int>> adj) {
    vector<int> dist(V + 1, INF);    // 전부 INF로 초기화 
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, 0));
    dist[k] = 0;
    pq.push(make_pair(0, k));    // 시작 정점 방문 

    while (!pq.empty()) {
        int cost = -pq.top().first;    // 방문한 정점의 dist 값 
        int cur = pq.top().second;    // 현재 방문한 정점 
        pq.pop();

        for (int i = 0; i < adj[cur].size(); i++) {    // 현재 방문한 정점의 주변 정점 모두 조사 
            int next = adj[cur][i];    // 조사할 다음 정점 
            int nCost = cost + 1;    // 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용 
            if (nCost < dist[next]) {     // 기존 비용보다 현재 방문한 정점을 거친 비용이 더 싸다면 
                dist[next] = nCost;    // 갱신 
                pq.push(make_pair(-nCost, next));    // pq에 저장 
            }
        }
    }

    return dist;
}

int main()
{
    int N, M, K, X;
    int cnt = 0;
    vector< vector<int> > adj;
    cin >> N >> M >> K >> X;
    
    adj.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
 
    vector<int> dist = dijkstra(X, N, adj);
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i <<"\n";
            cnt += 1;
        }
    }
    if (cnt == 0) {
        cout << "-1";
    }
}
