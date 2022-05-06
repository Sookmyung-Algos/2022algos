#include <iostream>
#define MAX 21
using namespace std;

int N;  // N: 도시 개수
int roads[MAX][MAX];
int result[MAX][MAX];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> roads[i][j];  // 이 시간은 최단 시간으로 플로이드-와샬 적용한 결과인 것.
            result[i][j] = roads[i][j];
        }
    }
    
    for(int k=1; k<=N; k++){  // k:경유
        for(int s=1; s<=N; s++){
            for(int e=1; e<=N; e++){
                if(s == e || s == k || k == e)
                    continue;
                if(roads[s][e] == (roads[s][k]+roads[k][e])){  // k를 경유하는 시간과 바로 가는 시간이 동일한 경우
                    result[s][e] = 0;  // 한번에 가는 길(s->e)은 없어도 됨
                }
                else if(roads[s][e] > (roads[s][k]+roads[k][e])){  // 거쳐가는 시간이 더 작은 경우는 roads[s][e]가 최단거리였다는 점에서 모순임
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }
    
    int sum = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            sum += result[i][j];
        }
    }
    
    cout << sum/2;  // 하나의 도로에 대해 두 번 더하므로 2로 나눠야 함
    
    return 0;
}
