#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 50
#define INF 2500000000

int n, m, s, e;

int earn[MAX];
bool visit[MAX] = {false, };
vector<long long> dist(MAX, INF);
vector<pair<int, int> > map[MAX];
queue<int> cycleNode;

bool BFS()  // cycleNode 중에서 도착점으로의 경로가 존재하는지 판단
{
    while (!cycleNode.empty()) {
        int cur = cycleNode.front(); cycleNode.pop();

        for (auto x : map[cur]) {
            int next = x.first;
            if (visit[next]) continue;
            visit[next] = true;
            cycleNode.push(next);
        }
    }
    if (visit[e]) return true; // BFS 돌려서 도착점에 방문 표시가 된다면 cycle을 통과하는 경로가 존재하는거임 -> Gee
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back({v, w});
    }
    for (int i = 0; i < n; ++i) {
        cin >> earn[i];
    }

    dist[s] = -earn[s];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) { // 정점 하나 선택
            for (auto cur : map[j]) { // 선택된 정점에 연결된 모든 간선
                int next = cur.first;
                long long nextCost = cur.second;
                if (dist[j] != INF && dist[next] > dist[j] + nextCost - earn[next]) { // 선택된 정점이 무한대가 아니어야 됨.
                    dist[next] = dist[j] + nextCost - earn[next];
                    if (i == n) { // v-1번 돌리고 v번째라면 위의 if문을 들어왔다는 것이 노드가 업데이트 됨을 의미. 그러므로 cycleNode
                        visit[j] = true; cycleNode.push(j); // cycleNode들은 방문 표시
                    }
                }
            }
        }
    }
    
    if (dist[e] == INF) cout << "gg" << endl; // 도착할 수 없음. (연결이 안 되어 있음)
    else {
        if (BFS()) cout << "Gee" << endl; // 도착했는데 가진 돈 무한대 : 음의 사이클을 통과해서 도착가능.
        else cout << -dist[e] << endl; // 가진 돈 : earn을 -로 표현해서 의미상은 어색하지만 Bellman-Ford에는 적합함.
    }
    return 0;
}
