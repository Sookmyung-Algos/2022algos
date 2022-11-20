#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result[3];
int map[2200][2200]; // N*N 배열(N이 3의 7승까지 주어짐)

// 단위 종이 내 모든 칸들이 모두 같은지 아닌지 판단하는 함수
bool check(int row, int col, int num) 
{
	int start = map[row][col];	// 시작점
	for (int i = row; i < row + num; i++) 
    {
		for (int j = col; j < col + num; j++) 
        {
			if (start != map[i][j]) // 시작점과 이동한 칸의 값이 다를 경우
				return false;
		}
	}
	return true;
}

// 9분할로 나누는 함수
void divide(int row, int col, int num) 
{

	// 지금 단위 종이 내 모든 칸들의 값이 같을 경우
	if (check(row, col, num)) 
    {
		result[map[row][col]]++;
	}
	else // 단위 종이 내 칸 중 다른 값이 하나라도 있는 경우
    {
		// 새로운 단위사이즈를 만든다.
        // 처음에 num=27이었다면 다음 단위 정사각형은 한 변의 길이가 9
		int size = num / 3; 
		
		for (int i = 0; i < 3; i++) 
        {
			for (int j = 0; j < 3; j++) 
            {
                // 재귀
				divide(row + size * i, col + size * j, size);
			}
            // 최종적으로 9분할이 되도록 함.
		}
	}
}


int main() 
{
	int N; // N*N 크기 사용자에게 입력 받아 지정
	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
    {
		for (int j = 0; j < N; j++) 
        {
			int input; // -1, 0, 1 중 하나의 값 입력
			scanf("%d", &input);
			input++; // -1, 0, 1 을 각각 0, 1, 2로 표현	
			map[i][j] = input;
		}
	}
	divide(0, 0, N); // 다른 값 있으면 반복하여 9분할
	printf("%d\n%d\n%d", result[0], result[1], result[2]);

}
