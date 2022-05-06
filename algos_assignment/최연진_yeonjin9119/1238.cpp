#include <cstdio>
#include <algorithm>
using namespace std;
 
int dist[1001][1001];
 
int main(){
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = 1000000;
        }
        dist[i][i] = 0;
    }
 
    for(int i=0; i<m; i++){
        int s, e, v;
        scanf("%d %d %d", &s, &e, &v);
        dist[s][e] = min(dist[s][e], v);
    }
 
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    int re = 0;
    for(int i=1; i<=n; i++){
        re = max(re, dist[i][x] + dist[x][i]);
    }
    printf("%d", re);
 
    return 0;
}
