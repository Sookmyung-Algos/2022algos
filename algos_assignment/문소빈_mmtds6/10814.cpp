#include <algorithm>
#include <iostream>
using namespace std;

struct person {
	int age;
	char name[101];
	int join;
} member[100000];

bool cmp(struct person a, struct person b) {
	if (a.age == b.age) {
		return a.join < b.join;
	}
	else {
		return a.age < b.age;
	}
}

int main() {

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &member[i].age, &member[i].name);
		member[i].join = i;
	}

	sort(member, member + n, cmp);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", member[i].age, member[i].name);
	}

	return 0;
}
