#include <iostream>
#include <queue>
#include <string.h>

#define MAX 50
using namespace std;

int n, l, r;
int sum = 0;
int arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void dfs(int x, int y) {
    v.push_back(make_pair(x, y));
    visit[x][y] = true;
    sum += arr[x][y];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) 
            continue;
        if (abs(arr[nx][ny] - arr[x][y]) < l || abs(arr[nx][ny] - arr[x][y]) > r) 
            continue;
        dfs(nx, ny);
    }
}

int main() {
    int ans = 0;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        memset(visit, false, sizeof(visit));
        vector<pair<pair<int, int>, int>> record;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    v.clear(); sum = 0;
                    dfs(i, j);

                    if (v.size() == 1) {
                        visit[i][j] = false;
                        cnt++;
                        continue;
                    }

                    int num = sum / v.size();
                    for (int i = 0; i < v.size(); i++) {
                        record.push_back({ {v[i].first, v[i].second}, num });
                    }
                }
            }
        }

        if (cnt == n * n) break;

        for (int i = 0; i < record.size(); i++) {
            int x = record[i].first.first;
            int y = record[i].first.second;
            int num = record[i].second;

            arr[x][y] = num;
        }

        ans++;
    }

    cout << ans;

    return 0;
}
