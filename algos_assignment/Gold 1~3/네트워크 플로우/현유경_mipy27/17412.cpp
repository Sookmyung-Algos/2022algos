#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 401

using namespace std;

int N,P;
int result;
int minflow = 987654321;

int c[MAX][MAX];
int flow[MAX][MAX];

vector<vector<int>> edge;

int maxFlow(){
    
    while (1){
        queue<int> q;
        q.push(1);
        
        vector<int> v(N+1,-1);
        
        while (!q.empty()){
            int current = q.front();
            q.pop();
            
            for (int next:edge[current]){
                if (c[current][next] - flow[current][next] > 0 && v[next]==-1){
                    q.push(next);
                    v[next] = current;
                    
                    if (next==2) break;
                }
            }
        }
        
        if (v[2] == -1) break; // 없는 경우
        
        for (int i=2;i!=1;i=v[i]){
            minflow = min(minflow, c[v[i]][i] - flow[v[i]][i]);
        }
        
        for (int i=2;i!=1;i=v[i]){
            flow[v[i]][i] += minflow;
            flow[i][v[i]] -= minflow;
        }
        result += minflow;
    }
    return result;
}

int main() {
    
    cin >> N >> P;
    
    edge.resize(N+1);
    
    for (int i=0;i<P;i++){
        int a, b;
        cin >> a >> b;
        
        edge[a].push_back(b);
        edge[b].push_back(a);
        c[a][b]=1; // 단방향이기 때문에 용량을 한 쪽만 설정
    }
    
    cout << maxFlow() << '\n';
    
    return 0;
}
