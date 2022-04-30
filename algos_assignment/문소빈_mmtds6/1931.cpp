#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n, start, end = 0, max_cnt = -1;
	vector <pair<int, int>> v;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &start, &end);
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	int time = v[0].first;
	int cnt = 1;
	for (int j = 1; j < n; j++) {
		if (time <= v[j].second) {
			time = v[j].first;
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
