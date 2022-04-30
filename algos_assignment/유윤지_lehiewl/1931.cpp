#include <iostream>
#include<stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> table(n);
	for (int i = 0; i < n; i++) {
		cin >> table[i].second >> table[i].first;
	}
	sort(table.begin(), table.end());
	int time = 0, count = 0;
	for (int i = 0; i < n; i++) {
		if (time <= table[i].second) {
			time = table[i].first;
			count++;
		}
	}
	printf("%d", count);
}
