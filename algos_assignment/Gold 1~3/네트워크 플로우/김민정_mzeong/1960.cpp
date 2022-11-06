#include <bits/stdc++.h>
using namespace std;
const int n_ = 1010;

int n, s = 1001, t = 1002, bias = 500;
int d[n_];                  // 현재 정점 방문 여부
int c[n_][n_], f[n_][n_];   // 용량, 유량
int arr[n_][n_];            // 행렬
vector<int> v[n_];
int a[n_], b[n_];

void addEdge(int s, int e, int x){
    v[s].push_back(e);
    v[e].push_back(s);
    c[s][e] = x;
}

bool chk() {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) sum += arr[i][j];
        if (sum != a[i]) return false;
    }
    for (int j = 1; j <= n; j++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += arr[i][j];
        if (sum != b[j]) return false;
    }
    return true;
}

void Edmonds_Karp(){
    int flow = 1e9;
    while (1){
        fill(d, d + n_, -1);
        queue<int> q; q.push(s);
        while (!q.empty()){
            int cur = q.front(); q.pop();
            for (auto nxt : v[cur]){
                if (d[nxt] == -1 && c[cur][nxt] - f[cur][nxt] > 0){ // 방문하지 않은 노드 중에 용량이 남은 경우 
                    q.push(nxt);
                    d[nxt] = cur; // 경로를 기억함
                    // if (nxt == t) break; // 도착지에 도달한 경우
                }
            }
        }
        // 모든 경로를 다 찾은 경우
        if (d[t] == -1) break; 
        for (int i = t; i != s; i = d[i]){ // 거꾸로 최소 유량 탐색 
            int bef = d[i];
            flow = min(flow, c[bef][i] - f[bef][i]);
        }
        for (int i = t; i != s; i = d[i]){ // 최소 유량만큼 추가
            int bef = d[i];
            f[bef][i] += flow;
            f[i][bef] -= flow;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        addEdge(s, i, x); // source, row
        a[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        addEdge(i+bias, t, x); // sink, col
        b[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            addEdge(i, j+bias, 1); // row, col
        }
    }
    Edmonds_Karp();
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[i][j+bias]) arr[i][j] = 1;
        }
    }
    if (!chk()) cout << -1;
    else {
        cout << 1 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
}
