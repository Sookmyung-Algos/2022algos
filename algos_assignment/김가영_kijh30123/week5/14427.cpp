#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

vector<pii> tree;
vector<int> List;
const int inf = 1000000001;
int n, m, s;

void update(int tarIdx, int tarVal) {
	int curIdx = s + tarIdx - 1;
	tree[curIdx].first = tarVal;
	curIdx >>= 1;

	pii left, right;

	while (curIdx) {
		left = tree[curIdx << 1];
		right = tree[(curIdx << 1) + 1];

		if (left.first < right.first) tree[curIdx] = left;
		else if (right.first < left.first) tree[curIdx] = right;
		else {
			if (left.second < right.second) tree[curIdx] = left;
			else tree[curIdx] = right;
		}

		curIdx >>= 1;
	}
}

void init() {
	int cur = s - 1;
	pii left, right;
	while (cur--) {
		left = tree[cur << 1];
		right = tree[(cur << 1) + 1];

		if (left.first < right.first) tree[cur] = left;
		else if (right.first < left.first) tree[cur] = right;
		else {
			if (left.second < right.second) tree[cur] = left;
			else tree[cur] = right;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	cin >> n; //size

	s = pow(2, ceil(log2(n)));

	tree.assign(s << 1, pii{ inf, 0 });
	List.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> List[i]; //An
		tree[s + i - 1] = { List[i], i };
	}

	init();
	
	cin >> m; //count

	int select, i, k;
	while (m--) { //query
		cin >> select;

		if (select & 1) {
			cin >> i >> k;
			update(i, k);
		}
		else {
			cout << tree[1].second << '\n';
		}
	}
}
