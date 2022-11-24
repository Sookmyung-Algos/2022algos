#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<cmath>
using namespace std;

int N, M;
double u, v, x, y;
int parent[101];
double d, ans;
vector<pair<double, double>> star;
vector<tuple<double, int, int>> DIST;

int find(int u)
{
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v)
{
	u = find(u);
	v = find(v);

	// 부모 노드가 같다면 싸이클이	 생기므로 건너뜀
	if (u == v) return false;
	else
	{
		parent[u] = v; // 부모 노드 지정
		return true;
	}
}

double Cal_dist(double x1, double y1, double x2, double y2)
{
	double x_dist = pow(x1 - x2, 2);
	double y_dist = pow(y1 - y2, 2);

	return sqrt(x_dist + y_dist);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;

	// 자기 자신을 부모로 지정
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	// 별들의 좌표 입력
	star.push_back({ 0,0 });
	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y;
		star.push_back({x, y});
	}
	
	// i번째 별과 j번째 별 사이의 거리 계산
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			double r = Cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
			DIST.push_back({ r, i, j });
		}
	}

	sort(DIST.begin(), DIST.end());

	// MST 계산
	for (int i = 0; i < DIST.size(); i++)
	{
		x = get<1>(DIST[i]);
		y = get<2>(DIST[i]);
		d = get<0>(DIST[i]);
		if (union_node(x, y)) ans += d;		
	}

	printf("%.2f", ans);
}
