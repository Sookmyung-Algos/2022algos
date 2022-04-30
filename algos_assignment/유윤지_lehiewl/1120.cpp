#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int result = 50;
	for (int i = 0; i < b.size() - a.size() + 1; ++i) {//b에서 a와 가장 비슷한 부분 찾을때까지 반복
		int count = 0;

		for (int j = 0; j < a.size(); ++j) {
			if (a[j] != b[j + i]) {
				++count;
			}
		}
		result = min(result, count);
	}
	printf("%d",result);	
}
