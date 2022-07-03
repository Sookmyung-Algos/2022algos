#include <iostream>
using namespace std;
 
int T, N;
int mat[1001][10];
 
void setting() {
    for(int i = 0; i <= 9; i++) {
        mat[1][i] = 1;
    }
}
 
void func() {
    for(int i = 2; i <= 1000; i++) {
        for(int j = 0; j <= 9; j++) {
            switch(j) {
                case 0:
                    mat[i][j] = mat[i - 1][7];
                    break;
                case 1:
                    mat[i][j] = mat[i - 1][2] + mat[i - 1][4];
                    break;
                case 2:
                    mat[i][j] = mat[i - 1][1] + mat[i - 1][3] + mat[i - 1][5];
                    break;
                case 3:
                    mat[i][j] = mat[i - 1][2] + mat[i - 1][6];
                    break;
                case 4:
                    mat[i][j] = mat[i - 1][1] + mat[i - 1][5] + mat[i - 1][7];
                    break;
                case 5:
                    mat[i][j] = mat[i - 1][2] + mat[i - 1][4] + mat[i - 1][6] + mat[i - 1][8];
                    break;
                case 6:
                    mat[i][j] = mat[i - 1][3] + mat[i - 1][5] + mat[i - 1][9];
                    break;
                case 7:
                    mat[i][j] = mat[i - 1][4] + mat[i - 1][8] + mat[i - 1][0];
                    break;
                case 8:
                    mat[i][j] = mat[i - 1][5] + mat[i - 1][7] + mat[i - 1][9];
                    break;
                case 9:
                    mat[i][j] = mat[i - 1][6] + mat[i - 1][8];
                    break;
            }
            mat[i][j] = mat[i][j] % 1234567;
        }
    }
}
 
int main() {
    cin >> T;
    setting();
    func();
    while(T--) {
        int ans = 0;
        cin >> N;
        for(int i = 0; i < 10; i++) {
            ans += mat[N][i];   
        }
        cout << ans % 1234567 << '\n';
    }
}
