#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int A[50][50];
bool visit[50][50];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int N, L, R;

bool canopen(int y, int x){
    for (int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (abs(A[y][x] - A[ny][nx]) >= L && abs(A[y][x] - A[ny][nx]) <= R) return true;
    }
    return false;
}

bool canopen2(int y, int x, int ny, int nx){
    if (abs(A[y][x] - A[ny][nx]) >= L && abs(A[y][x] - A[ny][nx]) <= R) return true;
    return false;
}

void bfs(int a, int b){
    queue<pair<int, int>> q, nq;
    q.push({a, b});
    nq.push({a, b});
    visit[a][b] = true;
    int sum = 0, cnt = 0;
    
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        sum += A[y][x];
        cnt++;
        
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visit[ny][nx]) continue;
            if (canopen2(y, x, ny, nx)) {
                visit[ny][nx] = true;
                q.push({ny, nx});
                nq.push({ny, nx});
            }
        }
    }
    
    int population = sum / cnt;
    while (!nq.empty()) {
        int y = nq.front().first;
        int x = nq.front().second;
        nq.pop();
        A[y][x] = population;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int day = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (!visit[i][j] && canopen(i, j)) {
                    bfs(i, j);
                    flag = true;
                }
            }
        }
        if (flag) day++;
        memset(visit, false, sizeof(visit));
    }
    cout << day << '\n';
    return 0;
}
