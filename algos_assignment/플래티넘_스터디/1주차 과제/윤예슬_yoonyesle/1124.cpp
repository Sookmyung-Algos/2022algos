#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

bool isPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

bool f(int n) {
	int cnt = 0;
	for (int i = 0; n > 1; ++i)
		while (n % primes[i] == 0) {
			n /= primes[i];
			++cnt;
		}
	return isPrime(cnt);
}

int main() {
	int a, b, ans = 0;
	cin >> a >> b;
	for (int i = 2; i <= b; ++i)
		if (isPrime(i))
			primes.push_back(i);
	for (int i = a; i <= b; ++i)
		if (f(i)) ++ans;
	cout << ans;
	return 0;
}
