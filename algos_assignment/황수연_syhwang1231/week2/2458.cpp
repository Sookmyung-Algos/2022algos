#include <iostream>
#include <utility>
#include <vector>
#define MAX 501
using namespace std;

int N, M;  // N: 학생 수, M: 두 학생 키 비교한 횟수
int a, b;  // a인 학생이 b보다 작음 (a->b)
int graph[MAX][MAX];  // graph[a][b] -- -1: a->b, 0: don't know, 1: b->a
int result;  // 자신의 순서를 알 수 있는 학생들

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        graph[a][b] = -1;
        graph[b][a] = 1;
    }
    
    // floyd-warshall
    for(int k=1; k<=N; k++){  // k경유
        for(int s=1; s<=N;s++){  // s에서 시작
            for(int e=1; e<=N; e++){  // e 도착
                if(graph[s][e] == 0){  // 두 학생에 대해 순서를 모를때만 갱신
                    if(graph[s][k] == -1 && graph[k][e] == -1){
                        graph[s][e] = -1;
                        graph[e][s] = 1;
                    }
                    else if(graph[s][k] == 1 && graph[k][e] == 1){
                        graph[s][e] = 1;
                        graph[e][s] = -1;
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=N;i++){  //  각 학생의 행에 0의 개수가 1(자기 자신과의 관계는 모르므로)이면 위치 아는것임
        int zeroCount = 0;  // 0의 개수 세기
        for(int j=1;j<=N;j++){
            if(graph[i][j] == 0)
                zeroCount++;
        }
        if(zeroCount == 1)
            result++;
    }
    
    cout << result;
    return 0;
}
