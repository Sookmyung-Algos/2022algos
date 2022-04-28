#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 100;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int N;
int graph[MAX][MAX];
bool visit[MAX][MAX];

void dfs(int y, int x, int cnt){
    visit[y][x] = true;
    graph[y][x] = cnt;
    
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (graph[ny][nx] && !visit[ny][nx]) dfs(ny, nx, cnt);
    }
}

int bfs(int cnt){
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (graph[i][j] == cnt){
                visit[i][j] = true;
                q.push({i, j});
            }
        }
    }
    
    int result = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny <0 || ny >= N || nx < 0 || nx >= N) continue;
                if (graph[ny][nx] && graph[ny][nx] != cnt) return result;
                else if (!graph[ny][nx] && !visit[ny][nx]) {
                    visit[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
        result++;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }
    int cnt = 1;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (graph[i][j] && !visit[i][j]) dfs(i, j, cnt++);
        }
    }
    int result = INF;
    
    for (int i = 1; i < cnt; i++){
        memset(visit, false, sizeof(visit));
        result = min(result, bfs(i));
    }
    cout << result << '\n';
    return 0;
}
