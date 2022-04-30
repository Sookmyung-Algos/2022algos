#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person {
	int age;
	char name[101];
	int join;
}member[100000];

bool cmp(struct Person a, struct Person b) {
	if (a.age == b.age)
		return a.join < b.join;
	else return a.age < b.age;
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i <= num; i++) {
		scanf("%d %s", &member[i].age, &member[i].name);
		member[i].join = i;
	}
	sort(member, member + num, cmp);
	for (int i = 0; i < num; i++) {
		printf("%d %s\n", member[i].age, member[i].name);
	}
}
