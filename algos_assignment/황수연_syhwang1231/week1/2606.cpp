#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;
//dfs or bfs 사용
int n, pairs;
int numOfCom = 0;
bool isVisited[MAX] = { false, };
vector <int> comps[MAX];

void bfs(int from){
    isVisited[from] = true;  // 
    queue<int> q;
    q.push(from);
    
    while(!q.empty()){
        numOfCom++;
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<comps[cur].size();i++){
            int next = comps[cur][i];
            if(!isVisited[next]){
                isVisited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void) {
	cin >> n;  // 컴퓨터 수 
	cin >> pairs;  // 연결되어있는 컴퓨터 쌍의 수

	int a, b;

	for (int i = 0; i < pairs; i++) {
		cin >> a >> b;
		comps[a].push_back(b);
		comps[b].push_back(a);
	}

	//dfs(1);  // 1번 컴퓨터가 바이러스 걸림
	bfs(1);
	cout << numOfCom - 1;  // numOfCom에는 1번 컴퓨터도 포함됐으므로 -1
	return 0;
}

/*void dfs(int from) {
	isVisited[from] = true;  // 방문 표시
	int next;
	numOfCom++;

	for (int i = 0; i < comps[from].size(); i++) {  // from과 연결된 컴퓨터들에 대해
		next = comps[from][i];
		if (!isVisited[next])  // 방문하지 않은 노드에 대해
			dfs(next);  // dfs
	}
}*/
