#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int pos = 0;
	int book[51];

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> book[i];
		if (book[i] < 0)
			pos++;
	}

	sort(book, book + N);

	int ans = 0;
	for (int i = N - 1; i >= pos; i -= M) {
		ans += (book[i] * 2);
	}

	for (int i = 0; i < pos; i += M) {
		ans += (abs(book[i] * 2));
	}

	ans -= max(book[N - 1], abs(book[0]));
	cout << ans;

	return 0;
}
