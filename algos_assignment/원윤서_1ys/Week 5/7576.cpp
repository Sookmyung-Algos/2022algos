#include <iostream>
#include <queue>
const int MAX = 1001;

using namespace std;

int M, N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int path[MAX][MAX];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;

void printPath() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", path[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void BFS() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (map[ny][nx] == 0 && visited[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                path[ny][nx] = path[y][x] + 1;
            }
        }
    }

}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }

    BFS();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && path[i][j] == 0) { 
                cout << -1;
                return 0;
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (path[i][j] > ans) {
                ans = path[i][j];
            }
        }
    }
    cout << ans;
}

//참고: https://scarlettb.tistory.com/86
