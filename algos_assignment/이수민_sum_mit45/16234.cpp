#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 51
using namespace std;
 
int N, L, R;
int MAP[MAX][MAX];
int Visit[MAX][MAX];
int Country_Number;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool Check = true;

 
bool Can_Combination2(int x, int y){
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N){
            if (L <= abs(MAP[x][y] - MAP[nx][ny]) && abs(MAP[x][y] - MAP[nx][ny]) <= R) return true;
        }
    }
    return false;
} 
 
bool Can_Combination(int x, int y, int xx, int yy){
    if (L <= abs(MAP[x][y] - MAP[xx][yy]) && abs(MAP[x][y] - MAP[xx][yy]) <= R) return true;
    return false;
}
 
void BFS(int a, int b){
    queue<pair<int, int>> Q, Nq;
    Q.push(make_pair(a, b));
    Nq.push(make_pair(a, b));
    Visit[a][b] = true;
    int Sum = 0;
    int Cnt = 0;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        Sum = Sum + MAP[x][y];
        Cnt = Cnt + 1;                                           
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (Visit[nx][ny] != 0) continue;
            if (Can_Combination(x, y, nx, ny) == true)
            {
                Visit[nx][ny] = 1;
                Q.push(make_pair(nx, ny));
                Nq.push(make_pair(nx, ny));
            }
        }
    }
 
    int Value = Sum / Cnt;
    
    while (Nq.empty() == 0)
    {
        int x = Nq.front().first;
        int y = Nq.front().second;
        Nq.pop();
        MAP[x][y] = Value;
    }
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    
    int Day = 0;
    while (Check){
        Check = false;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)            {                    
                if (Visit[i][j] == 0 && Can_Combination2(i,j) == true){
                    BFS(i, j);
                    Check = true;
                }
            }
        }      
        if (Check == true) Day++;
        memset(Visit, false, sizeof(Visit));
    }
    cout << Day << endl;
 
    return 0;
}
