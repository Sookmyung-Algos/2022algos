#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i(0), N(0), num(0);
	priority_queue<int, vector<int>, greater<int>>pq;
	cin >> N;

	for (i = 0; i < N; ++i) {
		cin >> num;
		pq.push(num);
	}
	for (i; i < N * N; ++i) {
		cin >> num;
		pq.push(num);
		pq.pop();
	}

	cout << pq.top();
}
