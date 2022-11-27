#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int CITYMAX = 1000 + 1;
const int BUSMAX = 100000 + 1;
const int INF = 987654321;

int n, m;
int source, destination; //출발점, 도착점

vector<pair<int, int>> graph[CITYMAX];
vector<int> dijkstra(int start, int vertex) {

        vector<int> distance(vertex, INF); //start를 기준으로 거리
        distance[start] = 0; //자기 자신한테 가는 비용 0
        priority_queue<pair<int, int>> pq; //Cost, Vertex
        pq.push(make_pair(0, start)); //초기 비용과 시작점
        while (!pq.empty()) {
                 int cost = -pq.top().first; //거리의 부호를 바꾸어 거리가 작은 버스부터
                 int curVertex = pq.top().second;
                 pq.pop();

                 //최소거리를 원하므로
                 if (distance[curVertex] < cost)
                         continue;

                 //neighbor 다 확인
                 for (int i = 0; i < graph[curVertex].size(); i++) {
                         int neighbor = graph[curVertex][i].first;
                         int neighborDistance = cost + graph[curVertex][i].second;

                         //최소 경로 발견시 업데이트
                         if (distance[neighbor] > neighborDistance) {
                                 distance[neighbor] = neighborDistance;
                                 //거리의 부호를 바꾸어 거리가 작은 버스부터 꺼내지도록
                                 pq.push(make_pair(-neighborDistance, neighbor));
                         }
                 }
        }
        return distance;
}

int main(void) {
        cin >> n >> m;
        n++; //정점번호 1부터 시작
        for (int i = 0; i < m; i++) {
                 int start, end, cost;
                 cin >> start >> end >> cost;
                 graph[start].push_back(make_pair(end, cost));
        }

        cin >> source >> destination;
        vector<int> result = dijkstra(source, n);
        cout << result[destination] << endl; //source->destination 거리

        return 0;
}
