#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 50

using namespace std;
 
int N, L, R;
int MAP[MAX][MAX];
int Visit[MAX][MAX];
int Country_Number;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool chk = true;
 
void input() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

bool Can_Combination2(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if (L <= abs(MAP[x][y] - MAP[nx][ny]) && abs(MAP[x][y] - MAP[nx][ny]) <= R) return true;
        }
    }
    return false;
}

bool Can_Combination(int x, int y, int xx, int yy) {
    if (L <= abs(MAP[x][y] - MAP[xx][yy]) && abs(MAP[x][y] - MAP[xx][yy]) <= R) return true;
    return false;
}

void BFS(int a, int b) {
    queue<pair<int, int>> q, Nq;
    q.push(make_pair(a, b));
    Nq.push(make_pair(a, b));
    Visit[a][b] = true;
    int Sum = 0;
    int Cnt = 0;
 
    while (q.empty() == 0) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        Sum = Sum + MAP[x][y];
        Cnt = Cnt + 1;                                           
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (Visit[nx][ny] != 0) continue;
            if (Can_Combination(x, y, nx, ny) == true) {
                Visit[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                Nq.push(make_pair(nx, ny));
            }
        }
    }
 
    int Value = Sum / Cnt;
    
    while (Nq.empty() == 0) {
        int x = Nq.front().first;
        int y = Nq.front().second;
        Nq.pop();
        MAP[x][y] = Value;
    }
}
 
void Print() {
    cout << "########################################" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Visit[i][j] == 0) {
                cout << 0 << " ";
            }
            else {
                cout << Visit[i][j] << " ";
            }
        }
 
        cout << "\t\t";
        for (int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << "########################################" << '\n';
 
}
 
void solution() {
    int Day = 0;
    while (chk) {
        chk = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {                    
                if (Visit[i][j] == 0 && Can_Combination2(i,j) == true) {
                    BFS(i, j);
                    chk = true;
                }
            }
        }        
        if (chk == true) Day++;
        memset(Visit, false, sizeof(Visit));
 
    }
    cout << Day << endl;
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solution();
 
    return 0;
}
