//복습필요
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 500 + 1;
int n;
int inDegree[MAX];
int duration[MAX];
int result[MAX];
vector<int> graph[MAX];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int time;
		cin >> time;

		duration[i] = time;

		while (1) {
			int node;
			cin >> node;

			if (node == -1) break; 
			inDegree[i]++;
			graph[node].push_back(i);
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i); 
	} 

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int nextNode = graph[node][i];
			result[nextNode] = max(result[nextNode], result[node] + duration[node]);

			if (--inDegree[nextNode] == 0) q.push(nextNode); 
		}
	}

	for (int i = 1; i <= n; i++) cout << result[i] + duration[i] << "\n"; 
	return 0;
}
