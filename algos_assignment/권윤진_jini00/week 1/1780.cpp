#include <iostream>

using namespace std;

int paper[2188][2188];
int answer[3] = {0, };

bool check(int row, int col, int size) {
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            int temp = paper[row][col];
            if (temp != paper[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int row, int col, int size) {
    if (check(row, col, size) == true) {
        answer[paper[row][col] + 1]++;
    }
    else {
        int next = size / 3;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                solve(row + (next * i), col + (next * j), next);
            }
        }
    }
}

int main() {
    int n, num;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            paper[i][j] = num;
        }
    }
    
    solve(0, 0, n);
    
    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
    }
    
    return 0;
}
