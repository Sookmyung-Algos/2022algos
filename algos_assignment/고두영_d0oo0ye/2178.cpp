#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
char buf[101];
int n, m;
int dir[4][2] = {{0, 1}, {1, 0},{-1, 0}, {0, -1}};

void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    int x, y, nx, ny;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            ny = y + dir[k][0];
            nx = x + dir[k][1];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) 
                continue;
            if (map[ny][nx] != 1) 
                continue;

            map[ny][nx] = map[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}
int main()
{
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        cin >> buf;

        for (int x = 0; x < m; x++) {
            map[y][x] = buf[x] - '0';
        }
    }

    bfs();
    cout << map[n - 1][m - 1];
    return 0;
}
