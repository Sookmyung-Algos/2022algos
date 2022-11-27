#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> dijkstra(int k, int V, vector<pair<int, int> > adj[]) {
    vector<int> dist(V + 1, 100001);    // 전부 INF로 초기화 
    priority_queue<pair<int, int> > pq;

    dist[k] = 0;
    pq.push(make_pair(0, k));    // 시작 정점 방문 

    while (!pq.empty()) {
        int cost = -pq.top().first;    // 방문한 정점의 dist 값 
        int cur = pq.top().second;    // 현재 방문한 정점 
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < adj[cur].size(); i++) {    // 현재 방문한 정점의 주변 정점 모두 조사 
            int next = adj[cur][i].first;    // 조사할 다음 정점 
            int nCost = cost + adj[cur][i].second;    // 현재 방문한 정점을 거쳐서 다음 정점을 갈때의 비용 
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int start, end;
    cin >> N;
    cin >> M;
    vector<pair<int, int> > adj[1001];

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
    cin >> start >> end;


    vector<int> dist = dijkstra(start, N, adj);

    cout << dist[end];
    return 0;
}
