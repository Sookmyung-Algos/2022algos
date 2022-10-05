#include <iostream>
#include <set>
using namespace std;

int main() {
	int a, b, ans = 0;
	scanf("%d%d", &a, &b);
	set<int> s;
	for (int i = 0; i < a + b; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (s.find(tmp) != s.end())
			s.erase(tmp);
		else
			s.insert(tmp);
	}
	printf("%d", s.size());
	return 0;
}
