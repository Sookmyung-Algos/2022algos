#include <iostream>
#include <vector>
using namespace std;

int T, N, M, W; // 지점의 수, 도로의 수, 웜홀의 수
int dist[501];
bool possible;
vector<pair<pair<int, int>, int> > edge;

bool BellmanFord() {
    dist[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int cost = edge[j].second;

            if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }

    //싸이클 확인
    for (int i = 0; i < edge.size(); i++) {
        int from = edge[i].first.first;
        int to = edge[i].first.second;
        int cost = edge[i].second;

        if (dist[to] > dist[from] + cost) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> T; 
    while (T--) {
        for (int i = 0; i < 501; i++)
            dist[i] = 999999999;

        edge.clear();

        //input
        cin >> N >> M >> W;
        while (M--) {
            int s, e, cost; cin >> s >> e >> cost;
            edge.push_back(make_pair(make_pair(s,e), cost));
            edge.push_back(make_pair(make_pair(e,s), cost));
        }
        while (W--) {
            int s, e, cost; cin >> s >> e >> cost;
            edge.push_back(make_pair(make_pair(s,e), -cost));
        }

        // bellman-ford
        possible = BellmanFord();

        if (possible)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
