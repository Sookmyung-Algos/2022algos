#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, blank, filled; 
int arr[129][129]; 

void chk(int x, int y, int len) {
	int k = arr[x][y]; 
	
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (k != arr[i][j]) {
				chk(x, y, len / 2);
				chk(x, y + len / 2, len / 2); 
				chk(x + len / 2, y, len / 2);
				chk(x + len / 2, y + len / 2, len / 2); 
				return; 
			}
		}
	}

	if (k == 1) filled++;
	else blank++; 

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
		}
	}

	chk(0, 0, n); 
	cout << blank << "\n" << filled; 

	
	
	return 0;
}
