#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tlll;
#define MAX 9876543210

ll n,m;
ll map[1002][1002];
ll dijk[1002][1002];
bool visited[1002][1002];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solve(int y, int x){
    priority_queue<tlll, vector<tlll>, greater<tlll>> q;        // 비용, y, x
    visited[y][x] = true;
    q.push({map[y][x], y, x});
    
    while(!q.empty()){
        ll cost = get<0>(q.top());
        ll ny = get<1>(q.top());
        ll nx = get<2>(q.top());
        q.pop();
        visited[ny][nx] = true;

        if (ny == n-1 && nx == m-1){
            cout<<cost;
            return;
        }

        for (int k=0; k<4; k++){
            ll nexty = ny +dy[k];
            ll nextx = nx + dx[k];

            if (nexty < 0 || nextx < 0 || nexty>=n || nextx>=m)
                continue;

            if (!visited[nexty][nextx]){
                if (dijk[nexty][nextx] > cost+map[nexty][nextx]){
                    dijk[nexty][nextx] = cost+map[nexty][nextx];
                    q.push({dijk[nexty][nextx], nexty, nextx});
                }
            }
        }
    }
    cout<<"-1";
    return;
}

int main() {
	cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
              cin>>map[i][j];
               if (map[i][j] == -1)
                     visited[i][j] = true;
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            dijk[i][j] = MAX;
        }
    }

    if (map[0][0] == -1 || map[n-1][m-1] == -1)
        cout<<"-1";
    else
        solve(0,0);

	return 0;
}
