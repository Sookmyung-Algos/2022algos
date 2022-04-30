#include <iostream>
#include <algorithm>
using namespace std;

class client {
	public:
		int age;
		string name;
};

client* s = new client[100000];

bool cmp(client a, client b) {
	return a.age < b.age;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s[i].age >> s[i].name;
	}

	stable_sort(s, s + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << s[i].age << " " << s[i].name << '\n';
	}

	return 0;
}
