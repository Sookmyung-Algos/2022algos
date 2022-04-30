#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	
	int N, x, y;
	vector <pair<int, int>> v;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

	return 0;
}
