#include <iostream>
using namespace std;

int T;

bool check(char paper[], int s, int e)
{
	if (s >= e) return true;
	int l = s;
	int r = e;
	while (l < r)
	{
		if (paper[l] == paper[r]) return false;
		l++;
		r--;
	}
	return check(paper, s, r - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char paper[3010];

	cin >> T;
	while (T--) {
		cin >> paper;
		int len = strlen(paper);
		if (len % 2 == 0) cout << "NO" << endl;
		else if (check(paper, 0, len - 1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
