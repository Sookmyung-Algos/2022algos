#include <iostream>
#include <utility>
#include <vector>
#define MAX 401
using namespace std;

int n, k;  // n: 사건의 개수, k: 사건의 전후관계 개수
int a, b;  // a사건이 일어난 후 b사건이 일어남(input)
int s;  // s: 전후관계를 알고 싶은 사건 쌍의 수
int graph[MAX][MAX];  // [a][b] -> -1이면 a 다음 b, 1이면 b 다음 a, 모르면 0
vector<pair<int, int>> query;  // 사건 쌍 저장

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;  // 사건 전후관계 입력
    for(int i=0;i<k;i++){
        cin >> a >> b;
        graph[a][b] = -1;
        graph[b][a] = 1;
    }
    
    cin >> s;  // 알고싶은 사건 쌍 입력
    int x, y;
    for(int i=0;i<s;i++){
        cin >> x >> y;
        query.push_back({x,y});
    }
    
    for(int k=1; k<=n; k++){  // k를 경유
        for(int s=1; s<=n; s++){  // s: (전) 사건
            for(int e=1; e<=n; e++){  // e: (후) 사건
                if(graph[s][e] == 0){  //  알고자 하는 사건 쌍이 모르는 상태(0)인 경우에만 확인 후 갱신
                    if(graph[s][k] == 1 && graph[k][e] == 1){
                        graph[s][e] = 1;
                        graph[e][s] = -1;
                    }
                    else if(graph[s][k] == -1 && graph[k][e] == -1){
                        graph[s][e] = -1;
                        graph[e][s] = 1;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<s;i++)
        cout << graph[query[i].first][query[i].second] << "\n";
    
    return 0;
}
