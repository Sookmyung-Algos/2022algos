#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, test;
int cost[1001][1001];
int visited[1001];
int dp[1001];
vector<vector<int>> bridge;

int solve(int root) {
    if (bridge[root].size() == 1 && root != 1) return 21;

    int& ret = dp[root];
    if (ret != -1) return ret;
    ret = 0;

    visited[root] = 1;

    for (int i = 0; i < bridge[root].size(); i++) {
        if (visited[bridge[root][i]]) continue;

        int tmp = min(cost[root][bridge[root][i]], solve(bridge[root][i]));
        ret += tmp;
    }
    visited[root] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> test;

    while (test--) {
        cin >> n >> m;
        bridge.resize(n + 1);

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            bridge[a].push_back(b);
            bridge[b].push_back(a);
            cost[a][b] = c;
            cost[b][a] = c;
        }

        memset(dp, -1, sizeof(dp)); //함수메모리 초기화
        memset(visited, 0, sizeof(visited));

        cout << solve(1) << "\n" ;
        bridge.clear();
    }
    return 0;
}
