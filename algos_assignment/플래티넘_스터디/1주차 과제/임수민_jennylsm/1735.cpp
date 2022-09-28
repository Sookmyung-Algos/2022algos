#include <iostream>
using namespace std;

//최대공약수를 구하는 함수
int gcd(int, int);

int main()
{
	unsigned int up1, up2, down1, down2, result_up, result_down;
	unsigned int gys, gys2;

	cin >> up1 >> down1;
	cin >> up2 >> down2;

// 1. 통분하기
	gys = gcd(down1, down2); // 최대공약수 구하기

	// 두 분수의 분모가 서로소일 때
	if (gys == 1) 
	{
		result_down = down1 * down2; // 두 수의 곱
		up1 *= down2;
		up2 *= down1;
	}
	// 서로소가 아닐 때
	else
	{
		result_down = down1 * down2 / gys; // 최소공배수
		up1 = up1 * down2 / gys;
		up2 = up2 * down1 / gys;
	}
	
// 2. 더하기
	result_up = up1 + up2;

	gys2 = gcd(result_up, result_down);
	
// 3. 약분하기. 결과로 나온 분자와 분모가 서로소가 아닐 경우에는 약분하자
	if (gys2 != 1)
	{
		result_up = result_up / gys2;
		result_down = result_down / gys2;
	}

	cout << result_up << " " << result_down;
}

int gcd(int a, int b)
{
	int c;

	while(1) {

		c = a % b; // c = a를 b로 나눈 나머지
		if (c == 0) return b;
		a = b; // 나누는 수가 나눠지는 수가 됨
		b = c; // 나머지가 나누는 수가 됨

	}

	return a; // 나눠지는 수를 리턴
}
