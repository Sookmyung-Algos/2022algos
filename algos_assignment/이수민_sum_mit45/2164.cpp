#include <iostream>
#include <queue>

using namespace std;

int main() {
	int input, topcard;
	queue <int> q;

	cin >> input;

	for (int i = 1; i <= input; i++) {
		q.push(i);
	}

	while (q.size() !=1){
		q.pop();
		topcard = q.front();
		q.pop();
		q.push(topcard);
	}

	cout << q.front();

	return 0;
}
