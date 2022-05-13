#include <iostream>
#include <algorithm>
using namespace std;
int INF = 10000000;
int N, M;
int arr[110][110];

void floyd(void) {

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				else if (arr[i][k] != 0 && arr[k][j] !=0) //i와 k가 연결되어있고, k와 j가 연결되어 있다.
				{
					if (arr[i][j] == 0)
						arr[i][j] = arr[i][k] + arr[k][j]; //없으면 바로 넣고
					else	
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]); //있으면 비교 후 넣음
				} //갱신
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int a, b;

	for(int i = 0; i < M; i++) {
		cin >> a >> b;

		arr[a][b] = arr[b][a] = 1;
	}

	floyd();

	int ans, res = INF;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++)
			sum += arr[i][j];
		if (res > sum) {
			res = sum;
			ans = i; // 그때의 사람 수
		}
	}
	cout << ans;
	return 0;
}
