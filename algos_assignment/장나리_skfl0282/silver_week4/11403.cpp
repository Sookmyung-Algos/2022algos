#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N;
int list[MAX][MAX];

void floyd() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (list[i][k] && list[k][j])
					list[i][j] = 1;
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
	floyd();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << list[i][j] << " ";
		}
		cout << "\n";
	}
}
