// 여름방학 1일차 B.프랙탈 평면
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int s, N, K;  // 시간 s, 1초마다 N×N짜리로 나뉨, 나누어진 정사각형이 흰색이라면 가운데 K×K짜리가 검은색
int r1, r2, c1, c2;  // R1행 C1열부터 R2행 C2열 내용을 출력

int solve(int length, int x, int y){  // 현재 위치 [x][y], 현재 길이 length
    if(length == 1)  // base case.?
        return 0;
    length /= N;  // N*N짜리로 나뉘었을 때 정사각형 한 변 길이
    
    // 검은색이 될 조건에 해당하는지
    if(x >= length*(N-K)/2 && x< length*(N+K)/2 && y >= length*(N-K)/2 && y < length*(N+K)/2)
        return 1;
        
    // 흰색이면 분할해서 다시 탐색
    return solve(length, x%length, y%length);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;
    
    int length = pow(N, s);  // 결국 다 쪼개졌을 때 정사각형 개수는 N^s
    
	for (int r = r1; r <= r2; r++) {
		for (int c = c1; c <= c2; c++) {
			cout << solve(length, r, c);  // 흰색은 0, 검정은 1
		}
		cout << "\n";
	}
    
    return 0;
}
