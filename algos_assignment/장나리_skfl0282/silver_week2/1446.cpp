#include <vector>
#include <iostream>
#include <queue>

#define MAX 20001        // 최대 정점의 개수 
#define INF 1e9

using namespace std;

int main()
{
    int N, D;
    cin >> N >> D;
    vector<int> m(10005, INF);
    vector<pair<int, int> > adj[100001];

    for (int i = 0; i < N; i++) {
        int u, v, w;        
        cin >> u >> v >> w;
        if (v > D) {
            continue;
        }
        adj[v].push_back(make_pair(u, w));
    }

    m[0] = 0;

    for (int i = 1; i <= D; i++) {
        m[i] = m[i - 1] + 1;
        for (int j = 0; j < adj[i].size(); j++) {
            m[i] = min(m[i], m[adj[i][j].first] + adj[i][j].second);
        }
    }
    cout << m[D];
}
