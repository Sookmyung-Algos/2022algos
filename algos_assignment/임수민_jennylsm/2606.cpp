#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Graph {
public:
	void add_edge(int from, int to) {
		m_edges[from].push_back(to);
	}

	void bfs(int node) {
		queue<int> q;

		m_visited[node] = true;
		q.push(node);

		while (!q.empty()) {
			node = q.front();
			// cout << node << ' ';
			q.pop();

			for (auto& v : m_edges[node]) {
				if (!m_visited[v]) {
					m_visited[v] = true;
					q.push(v);
				}
			}
		}
	}

    size_t count_visited() const {
		return m_visited.size();
	}

private:
	map<int, bool> m_visited;
	map<int, vector<int>> m_edges;
};

int main() {
	int n;
	int edges;

	std::cin >> n;
	std::cin >> edges;

	Graph g;

	for (int i = 0; i < edges; ++i) {
		int from, to;
		std::cin >> from >> to;
		g.add_edge(from, to);
		g.add_edge(to, from);
	}

	g.bfs(1);

	std::cout << g.count_visited() - 1 << std::endl;

	return 0;
}
