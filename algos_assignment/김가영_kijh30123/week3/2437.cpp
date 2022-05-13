#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	int Num[1000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Num[i]; //무게 입력받기

	sort(Num, Num + N);//정렬

	int ans = 1; //최소값

	if (Num[0] == 1) {
		int sum = Num[0];
		for (int i = 1; i < N && sum >= Num[i] - 1; i++) sum += Num[i];
		ans = sum + 1;
	}
	cout << ans;
	return 0;
}
