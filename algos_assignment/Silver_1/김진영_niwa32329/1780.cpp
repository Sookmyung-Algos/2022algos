#include <iostream>
#include <string.h>

using namespace std;

int n; 
int map[2200][2200];
int ans[3]; 

bool allSame(int x, int y, int n) {
	int chk = map[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[x + i][y + j] != chk) {
				return false; 
			}
		}
	}
	return true; 
}

void makePaper(int x, int y, int n) {
	if (allSame(x, y, n)) {
		int num = map[x][y];
		ans[num + 1]++; 
		return; 
	}

	int div = n / 3; 

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			makePaper(x + div * i, y + div * j, div); 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	n = 0; 
	memset(map, 0, sizeof(map));
	memset(ans, 0, sizeof(ans)); 

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j]; 
		}
	}
	
	makePaper(0, 0, n); 

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n"; 
	}

	return 0;
}
