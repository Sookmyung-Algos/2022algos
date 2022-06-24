#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v[1001];
int visited[1001];

int dfs(int cur, int d) {
    visited[cur] = 1;
    
    // 리프 노드인 경우
    if (cur != 1 && v[cur].size() == 1) return d;
    
    // 리프 노드가 아닌 경우
    int sum = 0;
    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i].first;
        int nd = v[cur][i].second;
        if (next != 1 && visited[next] == 0) sum += dfs(next, nd);
    }
    return min(d, sum);
    
}

int main()
{
    int t; cin >> t;
    while (t--) {
        for (int i = 0; i < 1001; i++) { // 초기화
            v[i].clear();
            visited[i] = 0;
        }
        
        int n, m; cin >> n >> m;
        
        if (n == 1) { // 섬이 하나뿐인 경우
            cout << 0;
            continue;
        }
        
        for (int i = 0; i < m; i++) {
            int n1, n2, d;
            cin >> n1 >> n2 >> d;
            v[n1].push_back({n2, d});
            v[n2].push_back({n1, d});
        }
        
        int ans = 0;
        for (int i = 0; i < v[1].size(); i++) {
            ans += dfs(v[1][i].first, v[1][i].second);
        }
        cout << ans << '\n';
    }
    return 0;
}
