#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional> //greater 사용위한 헤더추가

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	pair<int, int> p[200001];
	priority_queue<int, vector<int>, greater<int> > pq;
	//우선순위 큐: 들어간 순서 상관없이 우선순위 높은 데이터가 선출
	//greater 내림차순
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);

	pq.push(p[0].second);

	for (int i = 1; i < n; ++i) {
		if (pq.top() <= p[i].first) {
			pq.pop();
			pq.push(p[i].second);
		}
		else {
			pq.push(p[i].second);
		}
	}

	cout << pq.size();

	return 0;
}
