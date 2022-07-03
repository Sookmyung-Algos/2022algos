#include <iostream>
#include <queue>

using namespace std;
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int box[1001][1001];
int M, N;

queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (box[nx][ny] == 0){
                    box[nx][ny] = box[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(){
    cin >> M >> N;
 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> box[i][j];
            
            if (box[i][j] == 1){
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();
    
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (box[i][j] == 0) {
                cout << -1 << "\n";
                return 0;
            }
            
            if (result < box[i][j]) {
                result = box[i][j];
            }
        }
    }
        
    cout << result - 1 << "\n";
 
    return 0;
}
