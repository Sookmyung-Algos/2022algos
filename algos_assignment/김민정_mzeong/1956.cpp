#include <iostream>
using namespace std;
int v, e, a, b, c;
long long arr[401][401];
long long INF = 2000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
    
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        arr[a][b] = c;
    }
    
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    long long ans = INF;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) continue;
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}
