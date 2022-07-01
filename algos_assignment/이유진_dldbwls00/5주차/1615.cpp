//복습필수...
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
int n, m;
vector <ll> nums;

struct IndexedTree {
	vector <ll> tree;
	vector <ll> num;
	int leafSize = 0, depth = 0;

	IndexedTree(vector <ll> num1) {
		num = num1;
		while (pow(2, depth) < num1.size()) {
			depth++;
		}
		leafSize = pow(2, depth);
		tree.resize(2 * leafSize);
	}

	void update(int node, int left, int right, int index, int diff) {
		if (index < left || right < index) {
			return;
		}
		else {
			tree[node] += diff;
			if (left != right) {
				ll mid = (left + right) / 2;
				update(node * 2, left, mid, index, diff);
				update(node * 2 + 1, mid + 1, right, index, diff);
			}
		}
	}

	ll query(int node, int left, int right, int qLeft, int qRight) {
		if (right < qLeft || qRight < left)	return 0;
		else if (qLeft <= left && right <= qRight)	return tree[node];
		else {
			ll mid = (left + right) / 2;
			return query(node * 2, left, mid, qLeft, qRight) + query(node * 2 + 1, mid + 1, right, qLeft, qRight);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	nums.resize(n + 1);
	IndexedTree h(nums);
	vector <pair<int, int>> chk;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		chk.push_back({ a,b });
	}

	sort(chk.begin(), chk.end());
	ll result = 0;
	for (int i = m - 1; i >= 0; i--){
		int b = chk[i].second;
		result += h.query(1, 1, h.leafSize, 1, b - 1);
		h.update(1, 1, h.leafSize, b, 1);
	}
	cout << result;
	return 0;
}
