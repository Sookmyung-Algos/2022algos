#include <iostream>
 
using namespace std;
 
int n, k, b;
bool isBroken[100001];
 
int main() {
	cin >> n >> k >> b;
	for (int i = 1; i <= b; i++) {
		int input; cin >> input;
		isBroken[input] = true;
	}
	int result = 100001;
	for (int anchor = 1; anchor <= n - k + 1; anchor++) {
		int cnt = 0;
		for (int move = anchor; move < anchor + k; move++) {
			if (isBroken[move]) cnt++;
		}
		result = min(result, cnt);
	}
	cout << result;
}
