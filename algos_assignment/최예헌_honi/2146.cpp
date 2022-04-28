#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define MAX 1000000001

ll n;
ll arr[101][101];
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};

void dfs(ll x, ll y, ll land) {
  arr[x][y] = land;

  for (int k=0; k<4; k++) {
    ll nx = x + dx[k];
    ll ny = y + dy[k];

    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        continue;
      
    if (arr[nx][ny] == 1)
        dfs(nx, ny, land);
  }
}

int bfs(ll x, ll y) {
    ll temp[100][100]={0,};
    ll land = arr[x][y];
    queue<pair<ll, ll>> q;
    
    temp[x][y] = 1;
    q.push({x,y});

    while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();

        if (land < arr[x][y])
            return temp[x][y] - 2;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (arr[nx][ny] == land)
                continue;
            if (temp[nx][ny] > 0)
                continue;
          
            temp[nx][ny] = temp[x][y] + 1;
            q.push({nx, ny});
        }
    }
  
    return 987654321;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    ll count=2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == 1) {
                dfs(i, j, count++);
            }
        }
    }
    ll result = 987654321;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > 1) {
                if (result>bfs(i,j))
                    result = bfs(i, j);
            }
        }
    }
    cout<<result;
}
