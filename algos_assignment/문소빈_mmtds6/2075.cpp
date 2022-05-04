#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, num, nthNum;
	priority_queue <int, vector <int>, greater<int>> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (q.top() < num) {
				q.pop();
				q.push(num);
			}
		}
	}

	nthNum = q.top();

	cout << nthNum;

	return 0;
}
