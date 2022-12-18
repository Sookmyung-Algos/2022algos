#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<pair<int, int> > adj[501];
const int INF = 1000000007;
queue<int> qu;

void bellmanford(int N, int src) {
    vector<int> upper(N + 1, INF);
    bool updated = false;
    upper[src] = 0;
    for (int iter = 0; iter < N; iter++) {
        updated = false;
        for (int here = 1; here <= N; here++)
            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        if (!updated) {
            cout << "NO" << endl;
            break;
        }
    }
    if (updated)
        cout << "YES" << endl;
}

int main() {
    int TC, N, M, W;
    int start, end, time;

    cin >> TC;

    for (int k = 0; k < TC; k++) {
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < M; i++) {
            cin >> start >> end >> time;
            adj[start].push_back({ end, time });
            adj[end].push_back({ start, time });
        }
        for (int i = 0; i < W; i++) {
            cin >> start >> end >> time;
            adj[start].push_back({ end, -time });
        }
        bellmanford(N, 1);

    }
    return 0;
}
