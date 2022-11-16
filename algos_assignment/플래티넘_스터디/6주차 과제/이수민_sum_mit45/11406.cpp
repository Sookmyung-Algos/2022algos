#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 223;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, a[MAX], b[MAX], lv[MAX], w[MAX], S = 0, E = 201;
struct Edge {
	int to, c, rev;
	Edge(int to, int c, int rev) :to(to), c(c), rev(rev) {}
};
vector<Edge> v[MAX];
void addEdge(int s, int e, int c) {
	v[s].push_back({ e,c,(int)v[e].size() });
	v[e].push_back({ s,0,(int)v[s].size() - 1 });
}
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : v[cur]) {
			if (i.c && lv[i.to] == -1) {
				lv[i.to] = lv[cur] + 1;
				q.push(i.to);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int c) {
	if (cur == E)return c;
	for (; w[cur] < v[cur].size(); w[cur]++) {
		Edge& e = v[cur][w[cur]];
		if (!e.c || lv[e.to] != lv[cur] + 1)
			continue;
		int f = dfs(e.to, min(c, e.c));
		if (f > 0) {
			e.c -= f;
			v[e.to][e.rev].c += f;
			return f;
		}
	}
	return 0;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 101; i <= N + 100; i++) {
		cin >> a[i];
		addEdge(i, E, a[i]);
	}
	for (int i = 1; i <= M; i++) {
		cin >> b[i];
		addEdge(S, i, b[i]);
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 101; j <= N + 100; j++) {
			int f;
			cin >> f;
			addEdge(i, j, f);
		}
	}
	int ans = 0;
	while (bfs()) {
		memset(w, 0, sizeof(w));
		while (1) {
			int c = dfs(S, INF);
			if (!c)break;
			ans += c;
		}
	}
	cout << ans << "\n";
}
