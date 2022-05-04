#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	deque <int> dq;

	int n, m, num, index, cnt = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == num) {
				index = j;
				break;
			}
		}
		if (dq.size() / 2 >= index) {
			while (dq.front() != num) {
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}		
		}
		else {
			while (dq.front() != num) {
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		dq.pop_front();
	}

	cout << cnt;

	return 0;
}
