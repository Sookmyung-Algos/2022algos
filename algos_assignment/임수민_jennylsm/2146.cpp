#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAX = 102;
 
int n;
int arr[MAX][MAX];
bool check[MAX][MAX];
int map[MAX][MAX];
 
int group = 0;
 
struct coor {
    int y;
    int x;
};
 
struct coor2 {
    int y;
    int x;
    int cnt;
};
 
queue <coor> q;
queue <coor2> q2;
 
int ans = 987987987;
 
 
// inside check
bool inside(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
 
void bfs() {
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
 
        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (inside(ny, nx) && arr[ny][nx] == 1 && check[ny][nx] == 0) {
                check[ny][nx] = 1;
                map[ny][nx] = group;
                q.push({ ny,nx });
            }
        }
    }
}
 
void func(int g) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == g) {
                q2.push({ i,j,0 });
            }
        }
    }
 
    while (!q2.empty()) {
        int y = q2.front().y;
        int x = q2.front().x;
        int cnt = q2.front().cnt;
        q2.pop();
 
        int ny, nx;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (inside(ny, nx) && check[ny][nx] == 0 && map[ny][nx] == 0) {
                check[ny][nx] = 1;
                q2.push({ ny,nx,cnt + 1 });
            }
            else if (inside(ny, nx) && map[ny][nx] != 0 && map[ny][nx] != g) {
                if (cnt < ans) ans = cnt;
                return;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && check[i][j] == 0) {
                group++;
                check[i][j] = 1;
                map[i][j] = group;
                q.push({ i,j });
                bfs();
            }
        }
    }
 
 
    for (int g = 1; g <= group; g++) {
        memset(check, 0, sizeof(check));
        func(g);
        while (!q2.empty()) q2.pop();
    }
 
    cout << ans << endl;
 
    //디버깅
    /*
    cout << endl << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    
 
    return 0;
}
