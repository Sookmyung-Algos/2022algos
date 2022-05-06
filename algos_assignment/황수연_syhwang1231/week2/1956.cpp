#include <iostream>
#include <algorithm>
#define MAX 401
#define INF 9999999
using namespace std;

int v, e;  // v: 마을개수, e: 도로개수
int a, b, c;  // a: 시작마을, b: 도착마을, c: a에서 b로 가는 도로의 거리
int result = INF;  // 최소 사이클 도로 길이의 합
int graph[MAX][MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> v >> e;
    
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    
    // 플로이드-와샬
    for(int k=1; k<=v; k++){  // k: 경유
        for(int s=1; s<=v; s++){  // s: 출발
            for(int e=1; e<=v;e++){  // e: 도착
                if(graph[s][k]+graph[k][e] < graph[s][e])  // 더 작은 값으로 갱신
                    graph[s][e] = graph[s][k] + graph[k][e];
            }
        }
    }
    
    for(int i=1;i<=v;i++)
        result = min(result, graph[i][i]);
        
    cout << ((result == INF)? -1 : result);
    return 0;
}
