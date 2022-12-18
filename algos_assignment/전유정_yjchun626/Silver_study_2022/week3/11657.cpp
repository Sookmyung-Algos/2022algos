#include <iostream>
#include <vector>

#define MAX 987654321

using namespace std;
struct info {
	long long to, val;
};

info tmp;

vector<info> v[501]; // 벡터에 간선을 담는 형태
long long dist[501];
bool cycle = false;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int node, edge, from, to, result;
	long long val;
  
	cin >> node >> edge; // 입력 받는 모든 간선에 대한 정보를 시작점에 저장
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> val;
		tmp.to = to;
		tmp.val = val;
		v[from].push_back(tmp);
	}
	for (int i = 1; i <= node; i++) // dist[] 배열을 전부 MAX로 초기화
		dist[i] = MAX;
	dist[1] = 0; // 초기화 후, 노드 1에서 시작하기 때문에 dist[1] = 0을 추가적으로 설정

	for (int i = 1; i <= node; i++) { // n-1번의 순환 거친 후, n번째 순환에서 dist[to]가 갱신될 때, 음의 사이클이 존재한다고 판단
		for (int j = 1; j <= node; j++) {
			from = j;
      
			for (int k = 0; k < v[from].size(); k++) {
				to = v[from][k].to;
				val = v[from][k].val;
        
				if (dist[from] != MAX && dist[to] > dist[from] + val) { 
					if (i == node)
						cycle = true; // 음의 사이클 존재할 때 cycle = true로 설정
					dist[to] = dist[from] + val;
				}
			}
		}
	}
	if (cycle)
		cout << -1; // 사이클이 true인 경우 -1
	else {
		for (int i = 2; i <= node; i++) { // 사이클이 false인 경우 dist[] 값 출력 => dist[] 값이 MAX인 자리는 -1 출력
			if (dist[i] == MAX) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	return 0;
	system("pause");
}
