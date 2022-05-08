#include <iostream>
#include <list>

using namespace std;

int main() {
	int N, num;
	cin >> N;
	list<int> table;

	for (int i = 1; i <= N * N; i++) {
		cin >> num;
		table.push_back(num);
	}
	table.sort();
	list<int>::iterator it = table.begin();
	for (int i = 0; i <= N*N-N-1; i++) {
		*it++;
	}
	cout << (*it) << endl;
}
