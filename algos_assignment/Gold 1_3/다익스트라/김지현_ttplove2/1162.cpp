#include <iostream>
#include<string.h>
#include <algorithm>
#include <queue>
#include<cstdio>
#include <vector>
#define MAX 10001
using namespace std;

int N, M, K;
long long d[MAX][21];
priority_queue<pair<long long, pair<int, int>>> pq;
vector<pair<int, long long>> road[MAX];

long long dijkstra() {
    long long cost, newCost;
    int x, cnt, y;
    long long minCost;
	memset(d, 0x3f, sizeof(d));
	pq.push({ 0, {1, 0} });
	d[1][0] = 0;

	while (!pq.empty()) {
		cost = -pq.top().first;
		x = pq.top().second.first;
		cnt = pq.top().second.second;
		pq.pop();

		if (d[x][cnt] < cost) continue;

		for (int i = 0; i < road[x].size(); ++i) {
			y = road[x][i].first;
			newCost = cost + road[x][i].second;

			if (d[y][cnt] > newCost) { // 포장하지 않는 경우
				d[y][cnt] = newCost;
				pq.push({ -newCost,{y, cnt} });
			}
			if (cnt < K && d[y][cnt + 1] > cost) { // 포장하는 경우
				d[y][cnt + 1] = cost;
				pq.push({ -cost, {y, cnt + 1} });
			}
		}
	}
	minCost = d[N][0];
	for (int i = 1; i <= K; ++i) {
		if (minCost > d[N][i] && d[N][i] != -1) {
			minCost = d[N][i];
		}
	}
	return minCost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back(make_pair(b, c));
		road[b].push_back(make_pair(a, c));
	}

	cout << dijkstra();
	return 0;
}
