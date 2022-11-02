#include <iostream>
using namespace std;
typedef long long ll;

ll mat[2][2] = { {4,-1},{1,0} };
ll vec[2] = { 3,1 };

ll tmat[3][3];
ll tvec[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N; cin >> N;
	if (N & 1) cout << 0;
	else {
		N >>= 1;
		N--;
		while (N > 0) {
			if (N & 1) {
				for (int i = 0; i < 2; i++) {
					tvec[i] = 0;
					for (int k = 0; k < 2; k++) {
						tvec[i] += mat[i][k] * vec[k];
					}
				}
				for (int i = 0; i < 2; i++) {
					vec[i] = tvec[i] % 1000000007;
				}
			}

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					tmat[i][j] = 0;
					for (int k = 0; k < 2; k++) {
						tmat[i][j] += mat[i][k] * mat[k][j];
					}
				}
			}
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					mat[i][j] = tmat[i][j] % 1000000007;
				}
			}
			N >>= 1;
		}

		if (vec[0] < 0) vec[0] += 1000000007;
		cout << vec[0];
	}
}
