#include<iostream>
#include<list>

using namespace std;
list<int> a;
list<int>::iterator it = a.begin();

void f2() {
	int front = a.front();
	a.pop_front();
	a.push_back(front);
}

void f3() {
	int back = a.front();
	a.pop_back();
	a.push_front(back);
}

int find(int n) {
	int i;
	for (i = 0; i < a.size(); i++) {
		if (it == a.end())  it = a.begin();
		if (n = (*it) + i) break;
	}
	return i;
}

void move(int n) {
	int left = find(n);
	int right = a.size() - left - 1;
	if (left <= right) f2();
	else f3();

}

int main() {
	int N, M, elems[50], count = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) a.push_back(i);
	for (int i = 0; i < M; i++) cin >> elems[i];

	for (int i = 0; i < M; i++) {
		while (a.front() != elems[i]) {
			move(elems[i]);
			count++;
		}
		a.pop_front();
	}
	cout << count;
}
