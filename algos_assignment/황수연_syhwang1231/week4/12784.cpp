#define INF 100000000
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, M;  // T: test case, N: island, M: bridge
vector<vector<pair<int, int>>> islands;  // islands[i]: i와 연결돼있는 섬과 그 다이너마이트 개수 pair (first: island, second: dynamite)
vector<bool> visited;
int minDynamite;

int dfs(int node, int parent){
    int childSum = 0;
    visited[node] = true;
    
    for(int i=0; i<islands[node].size(); i++){
        pair<int, int> child = islands[node][i];
        if(visited[child.first])  // child가 node의 부모이면 continue
            continue;
        childSum += min(child.second, dfs(child.first, node));  // child-node간의 cost와 child의 자식들의 cost중 최소
    }
    
    if(childSum == 0)  // 리프노드인 경우
        childSum = INF;
    return childSum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> N >> M;
        islands.resize(N+1);
        visited.resize(N+1);
        
        for(int j=0; j<M; j++){
            int a, b, c;
            cin >> a >> b >> c;
            islands[a].push_back(make_pair(b,c));
            islands[b].push_back(make_pair(a,c));
        }
        int result = dfs(1, 0);  // 1부터 시작
        if(result == INF)  // 결과값이 INF인 경우, 즉 섬 1개만 존재
            cout << 0 << "\n";
        else
            cout << result << "\n";
        
        islands.clear();
        //memset(&islands[0], 0, sizeof(islands));  // out of bounds 에러남
        memset(&visited, false, sizeof(visited));
    }

    return 0;
}
