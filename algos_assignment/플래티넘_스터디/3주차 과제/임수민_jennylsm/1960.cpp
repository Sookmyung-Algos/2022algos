#include <iostream>
#include <queue>
using namespace std;

int n;
int rows[500];
int columns[500];
int matrix[500][500];

bool isMatrixValid() {
	int i, j;
	for (j = 0; j < n; j++) {
		int columnSum = 0;
		for (i = 0; i < n; i++) columnSum += matrix[i][j];

		if (columnSum != columns[j]) return false;
	}
	return true;
}

void solution() {
	int i, j;

	// 우선순위큐 초기화
	priority_queue<pair<int, int>> columnInfo; // (count, index) of column
	for (i = 0; i < n; i++) columnInfo.push({ columns[i], i });

	// row 단위로 greedy하게 진행
	for (i = 0; i < n; i++) {
		queue<pair<int, int>> poppedQueue; // 선택된 columnInfo의 원소들을 저장

		// 우선순위큐를 활용하여, 선택되어야할 column이 많은 것부터 선택
		for (j = 0; j < rows[i]; j++) {
			pair<int, int> popped = columnInfo.top(); columnInfo.pop();
			matrix[i][popped.second] = 1;
			poppedQueue.push({ popped.first - 1, popped.second });
		}

		// columnInfo <- poppedQueue
		while (!poppedQueue.empty()) {
			columnInfo.push(poppedQueue.front());
			poppedQueue.pop();
		}
	}

	// 행렬 체크
	if (!isMatrixValid()) {
		cout << "-1\n";
	}
	else {
		// 출력
		cout << "1\n";
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) cout << matrix[i][j];
			cout << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;

	int i;
	for (i = 0; i < n; i++) cin >> rows[i];
	for (i = 0; i < n; i++) cin >> columns[i];

	solution();

	return 0;
}
