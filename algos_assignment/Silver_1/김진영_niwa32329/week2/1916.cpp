#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int dp[1001];
vector<pair <int, int>> road[1001]; //버스의 정보 저장 

void bfs(int start) {
    //우선순위 큐 사용 
    //최소 힙: 비용이 적게 드는 지점부터 bfs로 탐색 
    priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second; 
        int cost = pq.top().first; 
        pq.pop();
        if (cost > dp[current]) { //이미 최소비용으로 갱신되어 있을 시 스킵 
            continue;
        }

        for (int i = 0; i < road[current].size(); i++) {
            int next = road[current][i].first;
            int next_cost = dp[current] + road[current][i].second;

            if (next_cost < dp[next]) {
                dp[next] = next_cost;
                pq.push({ next_cost,next });
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m; //도시의 개수 n, 버스의 개수 m 

    for (int i = 0; i < m; i++) { //버스의 정보 입력 
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({ b,c });
        //a : 시작 b: 도착 c: 금액
    }
    int start, end;
    cin >> start >> end; //출발 도시 번호, 도착지 도시 번호 
    fill_n(dp, 1001, 987654321);
    dp[start] = 0;
    bfs(start);

    cout << dp[end];

    return 0;
}
